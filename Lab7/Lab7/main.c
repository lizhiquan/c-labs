#include <stdio.h>
#include <ctype.h>
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

int is_valid_id(const char s[]) {
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
              
int is_valid_name(const char s[]) {
    return strlen(s) < NAMESIZE;
}

int is_valid_score(const int val) {
    return val >= 0 && val <= 100 ? 1 : 0;
}

void str_lower(char dest[], const char src[]) {
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

int main(void) {
    record rec;
    int status;
    
    while (1) {
        printf("Enter a record: ");
        status = read_record(&rec);
        
        if (status == -1) {
            printf("Invalid data!\n\n");
        } else if (status == 1) {
            printf("ID: %s\n", rec.id);
            printf("First name: %s\n", rec.name.first);
            printf("Last name: %s\n", rec.name.last);
            printf("Score: %d\n\n", rec.score);
        } else {
            break;
        }
    }
    
    return 0;
}
