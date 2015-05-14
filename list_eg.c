#include "my_list.h"

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
