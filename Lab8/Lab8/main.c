#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IDSIZE 10
#define NAMESIZE 20
#define BLOCK 2

#define CHECK(X) printf("%s...%s\n", (X) ? "passed" : "FAILED", #X)

typedef struct {
    char last[NAMESIZE];
    char first[NAMESIZE];
} name;

typedef struct {
    char id[IDSIZE];
    name name;
    int score;
} record;

typedef struct {
    record *data;
    size_t nalloc;
    size_t nused;
} record_list;

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
    record *temp;
    
    /* Allocated memory is used up */
    if (plist->nused == plist->nalloc) {
        temp = realloc(plist->data, plist->nalloc + BLOCK);
        
        /* Fail to allocate more space */
        if (temp == 0)
            return 0;
        
        /* Allocated successfully */
        plist->data = temp;
        plist->nalloc += BLOCK;
    }
    
    plist->data[plist->nused] = *prec;
    plist->nused++;
    return 1;
}

int main(int argc, const char * argv[]) {
    record_list rlist;
    record rec1, rec2, rec3;
    
    strcpy(rec1.id, "A01011221");
    strcpy(rec1.name.last, "Doe");
    strcpy(rec1.name.first, "John");
    rec1.score = 100;
    
    strcpy(rec2.id, "A09999999");
    strcpy(rec2.name.last, "Doe");
    strcpy(rec2.name.first, "Hanah");
    rec2.score = 80;
    
    strcpy(rec3.id, "A12345678");
    strcpy(rec3.name.last, "Doe");
    strcpy(rec3.name.first, "Kate");
    rec3.score = 90;
    
    list_init(&rlist);
    CHECK(rlist.data == NULL);
    CHECK(rlist.nalloc == 0);
    CHECK(rlist.nused == 0);
    
    list_insert(&rlist, &rec1);
    CHECK(strcmp(rlist.data[0].id, "A01011221") == 0);
    CHECK(rlist.nalloc == 2);
    CHECK(rlist.nused == 1);
    
    list_insert(&rlist, &rec2);
    CHECK(strcmp(rlist.data[1].id, "A09999999") == 0);
    CHECK(rlist.nalloc == 2);
    CHECK(rlist.nused == 2);
    
    list_insert(&rlist, &rec3);
    CHECK(strcmp(rlist.data[2].id, "A12345678") == 0);
    CHECK(rlist.nalloc == 4);
    CHECK(rlist.nused == 3);
    
    list_clear(&rlist);
    CHECK(rlist.data == NULL);
    CHECK(rlist.nalloc == 0);
    CHECK(rlist.nused == 0);
    
    return 0;
}
