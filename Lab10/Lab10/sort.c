#include "sort.h"
#include <string.h>
#include <stdlib.h>

static int score_desc_id_asc_cmp(const void *p, const void *q) {
    const record *pp = p;
    const record *qq = q;
    if (pp->score == qq->score)
        return strcmp(pp->id, qq->id);
    return qq->score - pp->score;
}

static int name_desc_id_asc_cmp(const void *p, const void *q) {
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

static int score_desc_name_asc_id_desc_cmp(const void *p, const void *q) {
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

void sort_score_desc_id_asc(record a[], size_t n) {
    qsort(a, n, sizeof(record), score_desc_id_asc_cmp);
}

void sort_name_desc_id_asc(record a[], size_t n) {
    qsort(a, n, sizeof(record), name_desc_id_asc_cmp);
}

void sort_score_desc_name_asc_id_desc(record a[], size_t n) {
    qsort(a, n, sizeof(record), score_desc_name_asc_id_desc_cmp);
}
