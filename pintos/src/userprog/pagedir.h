#ifndef USERPROG_PAGEDIR_H
#define USERPROG_PAGEDIR_H

#include <stdbool.h>
#include <stdint.h>
#include "vm/frame.h"

uint32_t *pagedir_create (void);
void pagedir_destroy (uint32_t *pd);
bool new_pagedir_set_page(uint32_t *pd, void *upage, struct frame *frame, bool rw);
bool pagedir_set_page (uint32_t *pd, void *upage, void *kpage, bool rw);
void *pagedir_get_page (uint32_t *pd, const void *upage);
void pagedir_clear_page (uint32_t *pd, void *upage);
bool pagedir_is_dirty (uint32_t *pd, const void *upage);
void pagedir_set_dirty (uint32_t *pd, const void *upage, bool dirty);
bool pagedir_is_accessed (uint32_t *pd, const void *upage);
void pagedir_set_accessed (uint32_t *pd, const void *upage, bool accessed);
void pagedir_activate (uint32_t *pd);
uint32_t *lookup_page (uint32_t *pd, const void *vaddr, bool create);
bool new_install_page (void *upage, struct frame *frame, bool writable);

#endif /* userprog/pagedir.h */
