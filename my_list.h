#ifndef __MY_LIST_H
#define __MY_LIST_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define VERBOSE true

#define DATA_TYPE int

typedef struct nodeT
{
        void *info;
        struct nodeT *next;
} Node;

typedef struct listT
{
        Node *head;
        Node *tail;
        int count;
} List;

void list_init(List *);
int insert_next(List *, Node *, const void  *);
int remove_node(List *, Node *, void  **);
void print_list(List *);

#define list_is_empty(list) (list->count==0 ? true:false)
#endif

