#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DATA_TYPE int

typedef struct nodeType_ 
{
        void *info;
        struct nodeType_ *next;
}nodeType;

typedef struct listType_
{
        nodeType *head;
        nodeType *tail;
        void (*destroy) (void *data);
        int count;
}listType;


void list_init(listType *list, void (*destroy) (void *data));
void list_destroy(listType *list);
int list_insert_next(listType *list, nodeType *node, const void *data);
int list_rem_next(listType *list, nodeType *node, void **data);

#define list_size(list) ((list)->count)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, node) ((list)-> head == node ? true : false)
#define list_is_tail(node) ((node)->next == NULL ? true : false)
#define list_data(node) ((node)->info)
#define list_next(node) ((node)->next)

#endif

