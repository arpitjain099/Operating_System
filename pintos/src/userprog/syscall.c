#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include <string.h>
#include "devices/input.h"
#include "devices/shutdown.h"
#include "threads/interrupt.h"
#include "threads/thread.h"
#include "threads/vaddr.h"
#include "threads/palloc.h"
#include "threads/malloc.h"
#include "threads/synch.h"
#include "userprog/pagedir.h" 
#include "userprog/process.h"
#include "filesys/file.h"
#include "filesys/filesys.h"
//my imp
#include "vm/frame.h"
//==my imp
struct file_descriptor {
  int fd_id;            /* FD unique identifier */
  tid_t owner;	        /* thread/process holding this FD */
  struct file *file;    /* reference to filesystem */
  struct list_elem elem;/* element for open_files list */
  char *exec_name;      /* name of the file (used to prevent ivalid writes)
                           in case it is executed currently */
};

struct list open_files;
struct lock file_lock;
int get_unique_fd_id (void);
struct file_descriptor* get_open_file (int fd);
struct file_descriptor* get_owned_file (int fd);

static void syscall_handler (struct intr_frame *);

bool is_valid_uaddr(const void *);
bool are_valid_uaddrs(const void *, int);

int sys_fork(void);
void halt (void);
int sys_test(void);
void exit (int) NO_RETURN;
tid_t exec_call (const char *);
bool create (const char *, unsigned);
bool remove (const char *);
int open (const char *);
int filesize (int);
int read (int, void *, unsigned);
int write (int, const void *, unsigned);
void seek (int, unsigned);
unsigned tell (int);
void close (int);

void
syscall_init (void) 
{
  intr_register_int (0x30, 3, INTR_ON, syscall_handler, "syscall");
  list_init (&open_files);
  lock_init (&file_lock);
}

static void
syscall_handler (struct intr_frame *f) 
{
 // printf("inside syscall_handler\n");
  int *esp,*q,*t;
  int ret;
  esp =f->esp;
  struct thread* cur;
  cur=thread_current();
  cur->in_syscall = true;
  switch(*esp)
    {
	case SYS_HALT: halt(); break;
	case SYS_EXIT: exit(*(esp+1)); break;
	case SYS_EXEC: t=exec_call((char *) *(esp + 1)); break;
	case SYS_WAIT: t=process_wait(*(esp+1)); break;
	case SYS_CREATE: t= (int) create((char *) *(esp+1),*(esp+2)); break;
	case SYS_REMOVE: t=(int ) remove((char *) *(esp+1)); break;
	case SYS_OPEN: t=open((char *) *(esp+1)); break;
	case SYS_FILESIZE: t=filesize(*(esp+1)); break;
	case SYS_READ: t=read(*(esp+1),(void *) *(esp+2), *(esp+3)); break;
	case SYS_WRITE: t=write(*(esp+1),(void *) *(esp+2),*(esp+3)); break;
	case SYS_SEEK: seek(*(esp+1),*(esp+2)); break;
	case SYS_TELL: t=tell(*(esp+1)); break;
	case SYS_CLOSE: close (* (esp + 1)); break;
	case SYS_TEST: t=sys_test(); break;
	case SYS_FORK: t=sys_fork(); break;
	  
    }
    cur->in_syscall=false;
  f->eax=t;
  return;
}

int sys_test(void)
{
	printf("test\n");
	return 0;

}
/* Halt the operating system. */
void halt (void) 
{
  //printf("I am, here\n");
  shutdown_power_off ();
}
int sys_fork()
{
  int c;
  printf("in fork\n");
  struct thread *cur;
  cur=thread_current();
  char *t="b";
  c=process_execute(t);
  thread_exit();
  return 0;
}
/* Prints the processes state and Name before
   terminating the process 
   (should only be called by userprocesses) */
void 
exit (int status) 
{
 printf("IN EXIT OPEN\n");
  struct thread *cur = thread_current ();
  char *p_name, *aux = cur->name;

  p_name = strtok_r (cur->name, " ", &aux);
  printf ("%s: exit(%d)\n", p_name, status);
  	
  /* close all owned files */
  struct list_elem *e;
  struct file_descriptor *fds; 

  lock_acquire (&file_lock);
  for(e = list_begin (&open_files); e != list_tail (&open_files); 
      e = list_next (e))
    {
      fds = list_entry (e, struct file_descriptor, elem);
      if (fds->owner == cur->tid)
        {
          e = list_prev (e);
          list_remove (&fds->elem);
          file_close (fds->file);	
          free (fds->exec_name);
          free (fds);
       }
    }
  lock_release (&file_lock);
  /* if (cur->parent != NULL && cur->own_exit_status != NULL) */
  /*   { */
  /*     cur->own_exit_status->status = status; */
  /*     /\* thread_exit wakes waiting process if existing. *\/ */
  /*   } */
  
  thread_exit ();
  printf("IN exit close\n");
}

/* Execute syscall:
   Creates a new thread and loads given file to execute (if exists).
   Returns tid of new thread or -1 if execution failed.  */
tid_t
exec_call (const char *file)
{
  tid_t new_pid = -1;
  /* get filename */
  char *p_name, *aux, *buf = palloc_get_page ( (enum palloc_flags)0);
  if (buf == NULL)
    {
      return -1;
    }
  ASSERT (strlcpy (buf, file, PGSIZE) > 0);
  aux = buf;
  p_name = strtok_r (NULL, " ", &aux);

  /* look if file exists */
  lock_acquire (&file_lock);
  struct file *f = filesys_open (p_name);
  lock_release (&file_lock);
  palloc_free_page (buf);

  /* if file exists create new process */
  if (f != NULL)
    {
      new_pid = process_execute (file);
    }
  return new_pid;
}

/* Creates a new file called file initially initial_size 
bytes in size. Returns true if successful, false otherwise.
Creating a new file does not open it: opening the new file 
is a separate operation which would require a open system call. */
bool 
create (const char *file, unsigned initial_size)
{
  if (!is_valid_uaddr (file))
    {
      exit (-1);
    }
  bool ret = false;
  lock_acquire (&file_lock);
  ret = filesys_create (file, initial_size);
  lock_release (&file_lock);
  return ret;
}

/* Deletes the file called file. Returns true if successful, 
false otherwise. A file may be removed regardless of whether 
it is open or closed, and removing an open file does not 
close it */
bool 
remove (const char *file) 
{
  if (!is_valid_uaddr (file))
    {
      exit (-1);
    }
  bool ret = false;
  lock_acquire (&file_lock);
  ret = filesys_remove (file);
  lock_release (&file_lock);
  return ret;
}

/* Opens the file called file. Returns a nonnegative integer 
handle called a "file descriptor" (fd), or -1 if the file 
could not be opened.  */
int 
open (const char *file) 
{	
  struct file_descriptor *fd;
  struct file *f;
  int status = -1;

  /* check if pointer is in userspace */
  if (!is_valid_uaddr (file))
    {
      exit (-1);
    }
	
  /* get file */
  lock_acquire (&file_lock);
  f = filesys_open (file);
  if (f != NULL)
    {
      fd = (struct file_descriptor *) malloc (sizeof (struct file_descriptor));
      /* abort if no memory */
      if (fd == NULL)
        {
          file_close (f);
          status = -1;
        }
      else
        {
          fd->fd_id = get_unique_fd_id ();
          fd->owner = thread_current ()->tid;
          fd->file = f;

          fd->exec_name = malloc (strlen (file) + 1); 
          ASSERT (strlcpy (fd->exec_name, file, strlen (file) + 1) > 0);
       
         list_push_back (&open_files, &fd->elem);
         status = fd->fd_id;
       }
   }
  lock_release (&file_lock);
  return status;
}

/* Returns the size, in bytes, of the file open as fd.  */
int 
filesize (int fd) 
{
  int ret = -1;
  lock_acquire (&file_lock);
  struct file_descriptor* fds = get_owned_file (fd);
  if (fds != NULL)
    {
      ret = file_length (fds->file);
    }
  lock_release (&file_lock);
  return ret;
}

/* Reads size bytes from the file open as fd into buffer. 
Returns the number of bytes actually read (0 at end of file), 
or -1 if the file could not be read (due to a condition other 
than end of file). */
int 
read (int fd, void *buffer, unsigned length) 
{
  if (!are_valid_uaddrs (buffer, length))
    {
      exit (-1);
    }
  int status = 0;
  lock_acquire (&file_lock);
  if (fd == STDOUT_FILENO)
    {
      status = -1;
    }
  else if (fd == STDIN_FILENO) 
    {
      /* read from stdin */
      int i = 0;
      char c;
      char* buf = (char *) buffer;
      while (length > 1 && (c = input_getc ()))
        {
          buf[i] = c;
          i++;
          length--;
        }
      buf[i] = 0;
      status = i;
    }
  else 
    {
      /* write to file */
      struct file_descriptor* fds = get_owned_file(fd);
      if (fds != NULL)
        {
          status = file_read(fds->file, buffer, length);
        }
      else
        {
          lock_release (&file_lock);
          exit (-1);
        }
    }
  lock_release (&file_lock);
  return status;
}

/* Writes size bytes from buffer to the open file fd. 
Returns the number of bytes actually written, which may 
be less than size if some bytes could not be written.  */
int 
write (int fd, const void *buffer, unsigned length) 
{
 	//printf("WRITE\n");
  if (!are_valid_uaddrs (buffer, length))
    {
      exit (-1);
    }
  int status = 0;
  lock_acquire (&file_lock);
  if (fd == STDIN_FILENO)
    {
      status = -1;
    }
  else if (fd == STDOUT_FILENO) 
    {
      /* write to stdout */
      putbuf (buffer, length);
      status = (int) length;
    }
  else 
    {
      /* write to file if not executed */
      struct file_descriptor* fds = get_owned_file (fd);
      /* if (fds != NULL) */
      /*   { */
      /*     if (file_executed (fds->exec_name)) */
      /*       { */
      /*         file_deny_write (fds->file); */
      /*       } */
      /*     else */
      /*       { */
      /*         file_allow_write (fds->file); */
      /*       } */
      /*     status = file_write (fds->file, buffer, length); */
      /*   } */
      /* else */
      /*   { */
      /*     lock_release (&file_lock); */
      /* 	  exit (-1); */
      /*   } */
    }
  lock_release(&file_lock);
  return status;
}

/* Changes the next byte to be read or written in
open file fd to position, expressed in bytes from 
the beginning of the file. */
void 
seek (int fd, unsigned position)
{
  lock_acquire (&file_lock);
  struct file_descriptor* fds = get_owned_file (fd);
  if (fds != NULL)
    {
      file_seek (fds->file, position);
    }
  lock_release (&file_lock);
}

/* Returns the position of the next byte to be read 
or written in open file fd, expressed in bytes from 
the beginning of the file. */
unsigned 
tell (int fd) 
{
  unsigned ret = 0;
  lock_acquire (&file_lock);
  struct file_descriptor* fds = get_owned_file (fd);
  if (fds != NULL)
    {
      ret = file_tell (fds->file);
    }
  lock_release (&file_lock);
  return ret;
}

/* Closes file descriptor fd. Exiting or terminating 
a process implicitly closes all its open file 
descriptors, as if by calling this function for 
each one.  */
void 
close (int fd) 
{
  struct file_descriptor *fds;
  lock_acquire (&file_lock);
  fds = get_owned_file (fd);
  if (fds != NULL)
    {
      list_remove (&fds->elem);
      file_close (fds->file);
      free (fds->exec_name);	
      free (fds);
    }
  else
    {
      lock_release (&file_lock);
      exit (-1);
    }
  lock_release (&file_lock);
}

/* Checks if given address is a vaild userprocess address. */
bool
is_valid_uaddr (const void *upointer) 
{
  struct thread *cur = thread_current ();
  if (upointer != NULL && is_user_vaddr (upointer))
    {
      return (pagedir_get_page (cur->pagedir, upointer)) != NULL;
    }
  return false; 
}

/* Check if the whole memory area from given pointer to pointer + offset
is valid in userporcess space */
bool
are_valid_uaddrs (const void *upointer, int size) 
{
  while(size > 0) 
    {
      /* check current "page" */
      if (!is_valid_uaddr (upointer))
        {
	  return false;
        }
        /* get next "page" */
        if(size >= PGSIZE)
          {
            size -= PGSIZE;
            upointer += PGSIZE;
          }
        else
          {
            /* check last address */
            upointer += size - 1;
            size = 0;
            if (!is_valid_uaddr (upointer)) 
              {
                return false;	
              }
       }
    }
  return true;
}

/* Returns a new unique file descriptor id */
int
get_unique_fd_id () 
{
  static int id = STDOUT_FILENO + 1;
  return id++;
}

/* Get a opened file by its fd */
struct file_descriptor *
get_open_file (int fd) 
{
  struct list_elem *e;
  struct file_descriptor *fds; 
  for(e = list_begin (&open_files); e!=list_tail (&open_files); 
      e = list_next (e))
    {
      fds = list_entry (e, struct file_descriptor, elem);
      if (fds->fd_id == fd)
        {
          return fds;
        }
    }
  return NULL;
}

/* Get the file if current_thread is the owner. */
struct file_descriptor *
get_owned_file (int fd) 
{
  struct file_descriptor* fds = get_open_file (fd);
  if (fds == NULL)
    {
      /* always call with file_lock hold */
      lock_release (&file_lock);
      exit (-1);
    }
  if (fds->owner == thread_current ()->tid)
    {
      return fds;
    }
  else
    {
      return NULL;
    }
}
