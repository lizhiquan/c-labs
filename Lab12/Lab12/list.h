#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include "record.h"

typedef struct node node;

struct node {
    record data;
    node *next;
};

typedef node *record_list;

void list_init(record_list *plist);
void list_clear(record_list *plist);
int list_insert(record_list *plist, const record *prec);
void list_apply(record_list *plist, void (*f)(const record *));

#endif
