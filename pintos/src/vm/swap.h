#ifndef VM_SWAP_H_
#define VM_SWAP_H_

#include <stdio.h>
#include <stdlib.h>
//#include "threads/palloc.h"

#define no_swap_pages 1000
struct swap
{
	void *pointer_to_swap_pages;
	bool filled;
};

void swap_init(void);
bool swap_read(void *frame,int index);
int swap_write(void *frame);
void swap_delete(int index);
#endif 
