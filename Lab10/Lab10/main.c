#include <stdio.h>
#include "list.h"
#include "io.h"
#include "sort.h"

int main(void) {
    record_list list;
    
    list_init(&list);
    
    while (1) {
        record rec;
        
        if (!read_record(&rec))
            break;
        
        list_insert(&list, &rec);
    }
    
    list_sort(&list, sort_score_desc_name_asc_id_desc);
    
    printf("\nSorted list:\n");
    
    list_apply(&list, print_record);
    
    list_clear(&list);
    
    return 0;
}
