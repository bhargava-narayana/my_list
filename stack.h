#ifndef STACK_H
#define STACK_H

#include "my_list.h"

typedef List Stack;

#define stack_init list_init
int stack_push(Stack *, const void *);
int stack_pop(Stack *, void **);
void stack_print(const Stack *);
//#define stack_peek(stack) (stack->head == NULL ? NULL : stack->head->info)
#define stack_peek(stack) (stack->head->info)
#define stack_size list_size


#endif
