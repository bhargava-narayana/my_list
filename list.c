#include "list.h"

void list_init(listType *list, void (*destroy) (void *data))
{
        list->count = 0;
        list->destroy = destroy;        
        list->head = NULL;
        list->tail = NULL;
        
        return;
}

void list_destroy(listType *list)
{
        void *data;

        //remove each element in the list
        while(list_size(list) > 0)
        {
                if(list_rem_next(list, NULL, (void **) &data) 
                                && list->destroy != NULL)
                {
                        //user-defined func to free 
                        //dynamically allocated mem
                        list->destroy(data);
                }
        }

        //no operations are allowed now
        //clear the struct as a precaution
        memset(list, 0, sizeof(list));

        return;
}

int list_insert_next(listType *list, nodeType *node, const void *data)
{
        nodeType *new_node;

        if((new_node = (nodeType *)malloc(sizeof(nodeType))) == NULL )
                return -1;

        new_node->info = (void *)data;

        //insert at head
        if(node == NULL)
        {
                if(list_size(list) == 0)
                {
                        list_tail(list) = new_node;
                }

                new_node->next = list->head;
                list->head = new_node;

        }
        //insert anywhere other then the head
        else
        {
                if(new_node->next == NULL)
                        list->tail = new_node;

                new_node->next = node->next;
                node->next = new_node;
        }
        //adjust node count
        list->count++;

        return 0;
}

int list_rem_next(listType *list, nodeType *node, void **data)
{
        nodeType *current;

        //donot remove from empty node
        if(list_size(list) == 0)
                return -1;

        //remove head
        if(node == NULL)
        {
                *data = list->head->info;
                current = list->head;
                list->head = list->head->next;

                if(list->count == 0)
                        list->tail = NULL;

        }
        //remove anywhere other then head
        else
        {
                if(node->next == NULL)
                        return -1;
                
                *data = node->next->info;
                current = node->next;
                node->next = node->next->next;

                if(node->next = NULL)
                        list->tail = node;
        }

        //free ptr
        free(current);

        //adjust node count
        list->count--;


        return 0;
}


int main(int argc, char *argv[])
{
        return EXIT_SUCCESS;
}
