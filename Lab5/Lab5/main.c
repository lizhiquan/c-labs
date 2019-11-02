#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LINESIZE 1024

int get_word(const char prompt[], char word[], size_t n) {
    char line[LINESIZE];
    
    while (1) {
        printf("%s", prompt);
        
        if (!fgets(line, LINESIZE, stdin)) {
            clearerr(stdin);
            return 0;
        }
        
        if (sscanf(line, "%s", word) == 1 && strlen(word) < n) {
            return 1;
        }
    }
}

int is_valid_id(const char s[]) {
    if (s[0] != 'a' && s[0] != 'A')
        return 0;
    
    if (!isdigit(s[1]) || !isdigit(s[2]) || !isdigit(s[3]) || !isdigit(s[4]) ||
        !isdigit(s[5]) || !isdigit(s[6]) || !isdigit(s[7]) || !isdigit(s[8]))
        return 0;
    
    if (s[9] != '\0')
        return 0;
    
    return 1;
}

int get_int(const char prompt[], int *p) {
    char line[LINESIZE];
    
    while (1) {
        printf("%s", prompt);
        
        if (!fgets(line, LINESIZE, stdin)) {
            clearerr(stdin);
            return 0;
        }
        
        if (sscanf(line, "%d", p) == 1) {
            return 1;
        }
    }
}

int is_valid_score(const int val) {
    return val >= 0 && val <= 100 ? 1 : 0;
}

int write_program(const char filename[]) {
    char stdId[LINESIZE];
    int score;
    FILE *fp;
    
    if ((fp = fopen(filename, "w")) == 0) {
        perror("fopen");
        return 3;
    }
        
    while (1) {
        do {
            if (!get_word("Enter an ID: ", stdId, 10)) {
                goto done;
            }
        } while (!is_valid_id(stdId));
        
        do {
            if (!get_int("Enter a score: ", &score)) {
                goto done;
            }
        } while (!is_valid_score(score));
            
        stdId[0] = tolower(stdId[0]);
        fprintf(fp, "%s %3d ", stdId, score);
    }
        
done:
    if (fclose(fp) != 0) {
        perror("fclose");
        return 4;
    }
    
    return 0;
}

int read_program(const char filename[]) {
    char stdId[LINESIZE];
    int score;
    int totalScore = 0;
    size_t count = 0;
    FILE *fp;
    
    if ((fp = fopen(filename, "r")) == 0) {
        perror("fopen");
        return 3;
    }
        
    while (fscanf(fp, "%s %d", stdId, &score) == 2) {
        printf("%s: %d\n", stdId, score);
        totalScore += score;
        count++;
    }

    printf("Average score: %.2f", (float) totalScore / count);
    
    if (fclose(fp) != 0) {
        perror("fclose");
        return 4;
    }
    
    return 0;
}

int main(int argc, const char * argv[]) {
    
    if (argc != 3) {
        fprintf(stderr, "usage: %s [mode(r/w)] [file_name]\n", argv[0]);
        return 1;
    }
    
    if (strcmp(argv[1], "w") == 0) {
        return write_program(argv[2]);
        
    } else if (strcmp(argv[1], "r") == 0) {
        return read_program(argv[2]);
    }
    
    fprintf(stderr, "invalid mode! Pass `r` for reading or `w` for writing.\nusage: %s [mode(r/w)] [file_name]\n", argv[0]);
    return 2;
}
