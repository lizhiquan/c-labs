#include "list.h"
#include <stdlib.h>

void list_init(record_list *plist) {
    *plist = NULL;
}

void list_clear(record_list *plist) {
    node *p;
    node *q;
    for (p = *plist; p != NULL; p = q) {
        q = p->next;
        free(p);
    }
    *plist = NULL;
}

int list_insert(record_list *plist, const record *prec) {
    node *newnode = malloc(sizeof(node));
    if (newnode == NULL)
        return 0;
    newnode->data = *prec;
    newnode->next = *plist;
    *plist = newnode;
    return 1;
}

void list_apply(record_list *plist, void (*f)(const record *)) {
    node *p;
    for (p = *plist; p != NULL; p = p->next)
        f(&p->data);
}
