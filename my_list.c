#include "my_list.h"

void list_init(List *list)
{
        list->head = NULL;
        list->tail = NULL;
        list->count = 0;
        if(VERBOSE)
                printf("list_init complete\n");
}

int insert_next(List *list, Node *node, const void *data)
{
        Node *new_node;
        void *ptr;

        if((new_node = (Node *)malloc(sizeof(Node))) == NULL)
                return -1;

        new_node->info = (void *)data;

        if(node == NULL)
        {
                if(list->count == 0)
                        list->tail = new_node;

                new_node->next = list->head;
               list->head = new_node; 
        }
        else
        {
                if(node->next ==NULL)
                {
                        list->tail = new_node;
                }
                
                new_node->next = node->next;
                node->next = new_node;
        }
        list->count++;
       
       /* 
        if(VERBOSE)
        {
                ptr = (int *)new_node->info;
                printf("new_node->info = %d", ptr);
        }
        */
        return 0;
}

int remove_node(List *list, Node *node, void **data)
{
        Node *current;

        if(list_is_empty(list))
        {
                fprintf(stdout, "remove_node: list is empty\n");
                return 1;
        }
        
        /*
         * removal of head
         */
        if(node == NULL)
        {
                *data = list->head->info;
                current = list->head;
                list->head = list->head->next;

                if(list->count == 1)
                        list->tail = NULL;
        }
        else {
                if(node->next == NULL)
                {
                        fprintf(stdout, "remove_node: invlaid data\n");
                        return -1;
                }
                
                *data = node->next->info;
                current = node->next;
                node->next = current->next->next;
                
                if(node->next == NULL)
                {
                        list->tail = node;

                }
        }
        free(current);
        list->count--;

        return 0;
}

void print_list(List *list)
{
        Node *current;
        DATA_TYPE *data;

        if(list_is_empty(list))
        {
                printf("empty list.nothing to print.\n");
                return;
        }

        current = list->head;
        printf("number of nodes= %d\n", list->count);
        printf("List_HEAD->");
        while(1)
        {
                data = current->info;
                fprintf(stdout, "%d->", *data);
                if(current == list->tail )
                        break;
                else
                        current = current->next;
        }
        printf("NULL\n");
        return;
}


int main(int argc, char *argv[])
{
        List my_list;
        Node *my_node;
        DATA_TYPE *data;
        int result;

        if((data = (DATA_TYPE *)malloc(sizeof(DATA_TYPE))) == NULL)
                return 1;

        list_init(&my_list);

        /*
         * inserting a node
         */
        *data = 5;
        if((result = insert_next(&my_list, NULL, data)) != 0)
        {
                printf("%d insert_next failed!\n", *data);
                return EXIT_FAILURE;
        }
        else {
                printf("insert_next of %d complete\n", *data);
        }
        print_list(&my_list);
      
       /*
        * removing a node
        */ 
        if((result = remove_node(&my_list, my_node,(void **)&data)) != 0)
        {
                printf("%d remove_node failed!\n", *data);
                return EXIT_FAILURE;
        }
        else {
                printf("remove_node of %d complete\n", *data);
        }
        print_list(&my_list);
       

        return EXIT_SUCCESS;
}
