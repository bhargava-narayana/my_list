#include "stack.h"

int stack_push(Stack *stack, const void *data)
{
        return (insert_next(stack, NULL, data));
}

int stack_pop(Stack *stack, void **data)
{
        return (remove_node(stack, NULL, data));
        
}
