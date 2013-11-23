#include "userprog/exception.h"
#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include "userprog/gdt.h"
#include "threads/interrupt.h"
#include "threads/thread.h"
#include "threads/palloc.h"
#include "threads/vaddr.h"
#include "threads/pte.h"
#include "vm/frame.h"
#include "vm/swap.h"
#include "userprog/process.h"
#include "userprog/syscall.h"
#include "userprog/pagedir.h"
#include "threads/malloc.h"
#include "vm/page.h"
#include "threads/init.h"

/* Number of page faults processed. */
static long long page_fault_cnt;

static void kill (struct intr_frame *);
static void page_fault (struct intr_frame *);
void noop(void)
{}
 
/* Registers handlers for interrupts that can be caused by user
   programs.

   In a real Unix-like OS, most of these interrupts would be
   passed along to the user process in the form of signals, as
   described in [SV-386] 3-24 and 3-25, but we don't implement
   signals.  Instead, we'll make them simply kill the user
   process.

   Page faults are an exception.  Here they are treated the same
   way as other exceptions, but this will need to change to
   implement virtual memory.

   Refer to [IA32-v3a] section 5.15 "Exception and Interrupt
   Reference" for a description of each of these exceptions. */
void
exception_init (void) 
{
  /* These exceptions can be raised explicitly by a user program,
     e.g. via the INT, INT3, INTO, and BOUND instructions.  Thus,
     we set DPL==3, meaning that user programs are allowed to
     invoke them via these instructions. */
  intr_register_int (3, 3, INTR_ON, kill, "#BP Breakpoint Exception");
  intr_register_int (4, 3, INTR_ON, kill, "#OF Overflow Exception");
  intr_register_int (5, 3, INTR_ON, kill,
                     "#BR BOUND Range Exceeded Exception");

  /* These exceptions have DPL==0, preventing user processes from
     invoking them via the INT instruction.  They can still be
     caused indirectly, e.g. #DE can be caused by dividing by
     0.  */
  intr_register_int (0, 0, INTR_ON, kill, "#DE Divide Error");
  intr_register_int (1, 0, INTR_ON, kill, "#DB Debug Exception");
  intr_register_int (6, 0, INTR_ON, kill, "#UD Invalid Opcode Exception");
  intr_register_int (7, 0, INTR_ON, kill,
                     "#NM Device Not Available Exception");
  intr_register_int (11, 0, INTR_ON, kill, "#NP Segment Not Present");
  intr_register_int (12, 0, INTR_ON, kill, "#SS Stack Fault Exception");
  intr_register_int (13, 0, INTR_ON, kill, "#GP General Protection Exception");
  intr_register_int (16, 0, INTR_ON, kill, "#MF x87 FPU Floating-Point Error");
  intr_register_int (19, 0, INTR_ON, kill,
                     "#XF SIMD Floating-Point Exception");

  /* Most exceptions can be handled with interrupts turned on.
     We need to disable interrupts for page faults because the
     fault address is stored in CR2 and needs to be preserved. */
  intr_register_int (14, 0, INTR_OFF, page_fault, "#PF Page-Fault Exception");
}

/* Prints exception statistics. */
void
exception_print_stats (void) 
{
  printf ("Exception: %lld page faults\n", page_fault_cnt);
}

/* Handler for an exception (probably) caused by a user process. */
static void
kill (struct intr_frame *f) 
{
  /* This interrupt is one (probably) caused by a user process.
     For example, the process might have tried to access unmapped
     virtual memory (a page fault).  For now, we simply kill the
     user process.  Later, we'll want to handle page faults in
     the kernel.  Real Unix-like operating systems pass most
     exceptions back to the process via signals, but we don't
     implement them. */
     
  /* The interrupt frame's code segment value tells us where the
     exception originated. */
  switch (f->cs)
    {
    case SEL_UCSEG:
      /* User's code segment, so it's a user exception, as we
         expected.  Kill the user process.  */
      printf ("%s: dying due to interrupt %#04x (%s).\n",
              thread_name (), f->vec_no, intr_name (f->vec_no));
      intr_dump_frame (f);
      thread_exit (); 

    case SEL_KCSEG:
      /* Kernel's code segment, which indicates a kernel bug.
         Kernel code shouldn't throw exceptions.  (Page faults
         may cause kernel exceptions--but they shouldn't arrive
         here.)  Panic the kernel to make the point.  */
      intr_dump_frame (f);
      PANIC ("Kernel bug - unexpected interrupt in kernel"); 

    default:
      /* Some other code segment?  Shouldn't happen.  Panic the
         kernel. */
      printf ("Interrupt %#04x (%s) in unknown segment %04x\n",
             f->vec_no, intr_name (f->vec_no), f->cs);
      thread_exit ();
    }
}

static const char *(strs[]) = {"false", "true"};
static inline const char* b(bool val) {return strs[val];}
static inline bool
is_stack_access (void * address, void * esp) {
  return (address < PHYS_BASE) 
      && (address > STACK_BOTTOM) 
      && (address + 32 >= esp);
}

/* Page fault handler.  This is a skeleton that must be filled in
   to implement virtual memory.  Some solutions to project 2 may
   also require modifying this code.

   At entry, the address that faulted is in CR2 (Control Register
   2) and information about the fault, formatted as described in
   the PF_* macros in exception.h, is in F's error_code member.  The
   example code here shows how to parse that information.  You
   can find more information about both of these in the
   description of "Interrupt 14--Page Fault Exception (#PF)" in
   [IA32-v3a] section 5.15 "Exception and Interrupt Reference". */
static void
page_fault (struct intr_frame *f) 
{
  bool not_present;  /* True: not-present page, false: writing r/o page. */
  bool write;        /* True: access was write, false: access was read. */
  bool user;         /* True: access by user, false: access by kernel. */
  void *fault_addr;  /* Fault address. */

  //void *esp;

  struct special_page_elem *gen_page;
  struct thread *cur = thread_current();

  /* Obtain faulting address, the virtual address that was
     accessed to cause the fault.  It may point to code or to
     data.  It is not necessarily the address of the instruction
     that caused the fault (that's f->eip).
     See [IA32-v2a] "MOV--Move to/from Control Registers" and
     [IA32-v3a] 5.15 "Interrupt 14--Page Fault Exception
     (#PF)". */
  asm ("movl %%cr2, %0" : "=r" (fault_addr));

	uint32_t *fault_page = (uint32_t *)(0xfffff000 & ((uint32_t) fault_addr));
	//printf("fault_addr=%p eip=%p\n", fault_addr, f->eip);
	ASSERT(fault_page !=NULL);
  /* Turn interrupts back on (they were only off so that we could
     be assured of reading CR2 before it changed). */
  intr_enable ();

  /* Count page faults. */
  page_fault_cnt++;
  
  /* Determine cause. */
  not_present = (f->error_code & PF_P) == 0;
  write = (f->error_code & PF_W) != 0;
  user = (f->error_code & PF_U) != 0;
  
  void *esp = f->cs == SEL_KCSEG ? cur->stack : f->esp;
  bool stack_access = is_stack_access(fault_addr, esp);
  if(is_kernel_vaddr(fault_addr))
    {
      if(user)
	{
	  // user process
	  process_exit();
	}
      else
	{
	  PANIC("kernel process");
	}
    }
  else
    {
      if(not_present==false)
	{
	  // write on readonly problem
	  process_exit();
	}
      else
	{
	  // not clear about esp
	  
	  gen_page = find_lazy_page (cur, fault_page);
	  
	  
	/*  if (gen_page == NULL && !stack_access) {
	    
	    struct list_elem *elem_test;
	    struct frame *f_test;
	    
	    switch (f->cs) {
	    case SEL_KCSEG:
	      if (!cur->in_syscall)
		printf("kernel page fault at 0x%08x\n", fault_addr);
	      ASSERT(cur->in_syscall && !!"page fault in kernel");
	      f->eip = (void *)f->eax;
	      f->eax = -1;
	      return;
	    default:
	      //exit (-1);
	      process_exit();
	    }
	  }*/
	  
	  struct frame *frame = ft_get_page (PAL_USER);   
	  if (frame == NULL){
	    printf ("Unable to get a page of memory to handle a page fault\n");
	    exit (-1);
	  }
	  uint32_t *kpage = frame->user_page;
	  frame->virtual_address = fault_page;
	  ASSERT (frame->t->pagedir !=NULL);
	  ASSERT (pg_ofs (frame->virtual_address)==0);
	  ASSERT (is_user_vaddr (frame->virtual_address));
	  ASSERT (frame->t->pagedir != init_page_dir);
	  uint32_t pte = lookup_page(frame->t->pagedir, frame->virtual_address, true);
	  frame->PTE = pte;
	  
	  bool writable = true;
	  bool dirty = false;
	  if (gen_page != NULL) 
	  {
	    switch (gen_page->type) 
	      {
	      case SWAP:
		;
		//printf("Case of swap page\n");
		//swap case to be handled
		struct swap_page *swap_page = (struct swap_page*) gen_page;
		
		dirty = swap_page->dirty;
		swap_read (kpage, swap_page->index);
		//doubt
		//palloc_free_page(kpage);
		swap_delete(swap_page->index);
		//doubt
		//delete swap_page in supplemental table.
		sema_down (&cur->page_sema);
		hash_delete (&cur->sup_pagetable, &swap_page->elem);
		sema_up (&cur->page_sema);
		
		if (swap_page->evicted_page != NULL)
		  add_lazy_page (thread_current (), swap_page->evicted_page);
		free(swap_page);
		break;
		case ZERO:
		memset(kpage, 0, PGSIZE);
		break;
	      }
	  }
	  else if(is_stack_access)
	  {
	    memset(kpage, 0, PGSIZE);	  	  
	  }
	  
	  lock_acquire (&frame_lock);
	  
	  /* Add the page to the process's address space. */
	  if (!new_install_page ((void *)fault_page, frame, writable)) {
	    lock_release (&frame_lock);
	    
	    ft_free_page (kpage);
	    // exit (-1);
	    process_exit();
	  }
	  
	  /* Set dirty bit if this frame is dirty before swaping to the swap disk. */
	   if (dirty)
	     pagedir_set_dirty (cur->pagedir, (void *)fault_page, true);
	   
	   frame->virtual_address = (uint32_t *) fault_page;
	   frame->loaded = true;
	   
	   lock_release (&frame_lock);
	}
    }
  /* To implement virtual memory, delete the rest of the function
     body, and replace it with code that brings in the page to
     which fault_addr refers. */
  /* printf ("Page fault at %p: %s error %s page in %s context.\n",
          fault_addr,
          not_present ? "not present" : "rights violation",
          write ? "writing" : "reading",
          user ? "user" : "kernel");
	  kill (f);*/
}

