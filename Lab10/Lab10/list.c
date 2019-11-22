#include "list.h"
#include <stdlib.h>

#define BLOCK 2

void list_init(record_list *plist) {
    plist->data = 0;
    plist->nalloc = 0;
    plist->nused = 0;
}

void list_clear(record_list *plist) {
    free(plist->data);
    plist->data = 0;
    plist->nalloc = 0;
    plist->nused = 0;
}

int list_insert(record_list *plist, const record *prec) {
    /* Allocated memory is used up */
    if (plist->nused == plist->nalloc) {
        record *temp = realloc(plist->data, (plist->nalloc + BLOCK) * sizeof(record));
        
        /* Fail to allocate more space */
        if (temp == 0)
            return 0;
        
        /* Allocated successfully */
        plist->data = temp;
        plist->nalloc += BLOCK;
    }
    
    plist->data[plist->nused++] = *prec;
    return 1;
}

void list_sort(record_list *plist, void (*sort)(record *, size_t)) {
    sort(plist->data, plist->nused);
}

void list_apply(record_list *plist, void (*f)(const record *)) {
    size_t i;
    for (i = 0; i < plist->nused; i++)
        f(&plist->data[i]);
}
