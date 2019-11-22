#include "io.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LINESIZE 1024

static int is_valid_id(const char s[]) {
    size_t i;
    
    if (s[0] != 'a')
        return 0;
    
    for (i = 1; i <= 8; i++)
        if (!isdigit(s[i]))
            return 0;
    
    if (s[9] != '\0')
        return 0;
    
    return 1;
}
              
static int is_valid_name(const char s[]) {
    return strlen(s) < NAMESIZE;
}

static int is_valid_score(const int val) {
    return val >= 0 && val <= 100 ? 1 : 0;
}

static void str_lower(char dest[], const char src[]) {
    size_t i;
    for (i = 0; src[i] != '\0'; i++)
        dest[i] = tolower(src[i]);
    dest[i] = '\0';
}

int read_record(record *prec) {
    char line[LINESIZE];
    char id[IDSIZE];
    char last[NAMESIZE];
    char first[NAMESIZE];
    int score;
    
    if (!fgets(line, LINESIZE, stdin)) {
        clearerr(stdin);
        return 0;
    }
    
    if (sscanf(line, "%s %s %s %d", id, first, last, &score) == 4) {
        if (is_valid_id(id) && is_valid_name(first) && is_valid_name(last) && is_valid_score(score)) {
            strcpy(prec->id, id);
            str_lower(prec->name.first, first);
            str_lower(prec->name.last, last);
            prec->score = score;
            return 1;
        }
    }
    
    return -1;
}

void print_record(const record *prec) {
    printf("%3d : %s, %s : %s\n", prec->score, prec->name.last, prec->name.first, prec->id);
}
