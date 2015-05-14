#ifndef __STACK_H
#define __STACK_H

#include "my_list.h"

typedef List Stack;

#define stack_init list_init
int stack_push(Stack *, const void *);
int stack_pop(Stack *, void **);
#define stack_peek(stack) (stack->head == NULL ? NULL:stack->head->info)
#define stack_size list_size


#endif
