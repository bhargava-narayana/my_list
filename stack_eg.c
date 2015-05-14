#include "stack.h"

int main(int argc, char *argv[])
{
        Stack my_stack;
        Node *stack_node;
        int *data;
        int i;

        stack_init(&my_stack);

        fprintf(stdout, "pushing 10 elements\n");
        for(i = 0; i < 10; i++)
        {
                if(data = (Node *)malloc(sizeof(Node)) == NULL)
                        return 1;
        
                *data = i + 1;
        
                if(stack_push(&my_stack, data) != 0)
                        return 1;
        }
        stack_print(&my_stack);

        fprintf(stdout, "popping 5 elements\n");
        for(i = 0; i < 5; i++)
        {
                if(strack_pop(&my_stack, (void **) data) == 0)
                        free(data);
                else
                        return 1;
        }
        stack_print(&my_stack);

        if(data = (stack_peek(&my_stack)) != NULL)
                fprintf(stdout, "stack_peek = %03d\n", *data);

        return EXIT_SUCCESS;
}
