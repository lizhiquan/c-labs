#ifndef RECORD_H
#define RECORD_H
#define IDSIZE 10
#define NAMESIZE 20

typedef struct {
    char last[NAMESIZE];
    char first[NAMESIZE];
} name;

typedef struct {
    char id[IDSIZE];
    name name;
    int score;
} record;

#endif
