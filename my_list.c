#include "my_list.h"

void list_init(List *list) {
        list->node_count = 0;
        list->head = NULL;
        list->tail = NULL;
        if(VERBOSE)
                printf("list_init complete. node_count = %d\n",list->node_count);
}

void list_print(List *list) {
        if(list_is_empty(list)) {
                printf("list is empty! nothing to print\n");
                return;
        }
        Node *current; 
        printf("LIST_HEAD->");
        while(current->next != NULL){
                printf("%d->",current->data);
                current = current->next;
        }
        printf("NULL\n");

}

int insert_next(List *list, Node *node, const void data) {
        Node *new_node;
        if((new_node = malloc(sizeof(Node))) == NULL) {
                printf("malloc failure! exiting..\n");
                return -1;
        }
        if(VERBOSE)
                printf("malloc successful! data = %d\n",data);
        return 0;

}
int main(int argc, char *argv[]) {

        List *list;
        Node *node;
        DATA_TYPE *data;
        
        data = 5;

        list_init(&list);
        list_print(&list);
        
        int result;
        result = insert_next(&list, NULL, data);
        if (result == 0) {
                list_print(&list);
        }
        else {
                printf("insert_next failed!\n");
        }


        return 0;
}

