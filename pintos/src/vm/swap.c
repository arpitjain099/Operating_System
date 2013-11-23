#include "vm/swap.h"
#include "threads/vaddr.h"
#include "threads/palloc.h"
#include "threads/synch.h"
#include "threads/malloc.h"
void *swap_base;

static struct lock swap_lock;

struct swap c[no_swap_pages];

void swap_init(void)
{
	int page;
	lock_init(&swap_lock);	
	swap_base=palloc_get_multiple(PAL_USER,no_swap_pages);
	//printf("Got swap pages=%p\n", swap_base);
	lock_acquire(&swap_lock);
	for(page=0;page<no_swap_pages;page++)
	{
	  c[page].pointer_to_swap_pages=(uint8_t *)swap_base + page*PGSIZE;
	  c[page].filled=false;
		//printf("a");
	}
	lock_release(&swap_lock);
}

bool swap_read(void *frame,int index)
{
  //printf("in swap_read index=%d\n", index);
	lock_acquire(&swap_lock);
	memcpy(frame,c[index].pointer_to_swap_pages,PGSIZE);
	lock_release(&swap_lock);
	return true;
}
int swap_write(void *frame)
{
        int d=0;
	lock_acquire(&swap_lock);
	for(;d<no_swap_pages;d++)
	{
		if(c[d].filled==false)
		{
			break;
		}
	}
	if(d==no_swap_pages)
	{
		//panic
		PANIC("OMG no space to write in swap disk ");
	}
	else
	{
		memcpy(c[d].pointer_to_swap_pages,frame,PGSIZE);
		c[d].filled=true;
	}
	lock_release(&swap_lock);
	//printf("out swap_write index=%d\n", d);
	return 	d;
}

void swap_delete(int index)
{
  //printf("in swap_delete index=%d\n", index);
  lock_acquire(&swap_lock);
  c[index].filled=false;
  lock_release(&swap_lock);
}
