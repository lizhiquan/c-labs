#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IDSIZE 10
#define NAMESIZE 20
#define LINESIZE 1024

typedef struct {
    char last[NAMESIZE];
    char first[NAMESIZE];
} name;

typedef struct {
    char id[IDSIZE];
    name name;
    int score;
} record;

int score_desc_id_asc_cmp(const void *p, const void *q) {
    const record *pp = p;
    const record *qq = q;
    if (pp->score == qq->score)
        return strcmp(pp->id, qq->id);
    return qq->score - pp->score;
}

void sort_score_desc_id_asc(record a[], size_t n) {
    qsort(a, n, sizeof(record), score_desc_id_asc_cmp);
}

int name_desc_id_asc_cmp(const void *p, const void *q) {
    const record *pp = p;
    const record *qq = q;
    const int lastCmp = strcmp(qq->name.last, pp->name.last);
    const int firstCmp = strcmp(qq->name.first, pp->name.first);
    if (lastCmp == 0) {
        if (firstCmp == 0)
            return strcmp(pp->id, qq->id);
        return firstCmp;
    }
    return lastCmp;
}

void sort_name_desc_id_asc(record a[], size_t n) {
    qsort(a, n, sizeof(record), name_desc_id_asc_cmp);
}

int score_desc_name_asc_id_desc_cmp(const void *p, const void *q) {
    const record *pp = p;
    const record *qq = q;
    if (pp->score == qq->score) {
        const int lastCmp = strcmp(pp->name.last, qq->name.last);
        const int firstCmp = strcmp(pp->name.first, qq->name.first);
        if (lastCmp == 0) {
            if (firstCmp == 0)
                return strcmp(qq->id, pp->id);
            return firstCmp;
        }
        return lastCmp;
    }
    return qq->score - pp->score;
}

void sort_score_desc_name_asc_id_desc(record a[], size_t n) {
    qsort(a, n, sizeof(record), score_desc_name_asc_id_desc_cmp);
}

int main(void) {
    record recs[100];
    size_t nRecs = 0;
    char line[LINESIZE];
    size_t i;
    
    while (1) {
        if (nRecs == 100)
            break;
        
        if (!fgets(line, LINESIZE, stdin)) {
            clearerr(stdin);
            break;
        }
        
        sscanf(line, "%s %s %s %d",
               recs[nRecs].id,
               recs[nRecs].name.last,
               recs[nRecs].name.first,
               &recs[nRecs].score);
        nRecs++;
    }
    
    sort_score_desc_name_asc_id_desc(recs, nRecs);
    
    printf("\nSorted records:\n");
    
    for (i = 0; i < nRecs; i++)
        printf("%d : %s, %s : %s\n",
               recs[i].score,
               recs[i].name.last,
               recs[i].name.first,
               recs[i].id);
    
    return 0;
}
