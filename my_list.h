#ifndef __MY_LIST_H
#define __MY_LIST_H

#ifndef TRUE 
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#define VERBOSE TRUE
#define DATA_TYPE int

#include <stdio.h>
typedef struct nodeT {
        void *data;
        struct nodeT *next; 
} Node;

typedef struct listT {
        int node_count;
        Node *head;
        Node *tail;
} List;

void list_init(List *list);
void list_print(List *list); 
int insert_next(List *list, Node *node, const void data);

#define list_is_empty(list) (list->node_count == 0? 1:0)


#endif
