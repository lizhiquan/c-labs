#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include "record.h"

void sort_score_desc_id_asc(record a[], size_t n);
void sort_name_desc_id_asc(record a[], size_t n);
void sort_score_desc_name_asc_id_desc(record a[], size_t n);

#endif
