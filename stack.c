#include "stack.h"

int stack_push(Stack *stack, const void *data)
{
        return (insert_next(stack, NULL, data));
}

int stack_pop(Stack *stack, void **data)
{
        return (remove_node(stack, NULL, data));
        
}

void stack_print(const Stack *stack)
{
        Node *current;
        int *data;
        int i;

        fprintf(stdout, "stack size= %d\n", stack_size(stack));

        i = 0;
        current = stack->head;
        while(i < stack_size(stack))
        {
                data = current->info;
                fprintf(stdout, "stack[%03d]= %03d]\n", i, *data);
                current = current->next;
                i++;
        }
        return;
}
