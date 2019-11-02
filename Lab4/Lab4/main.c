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

int main(int argc, const char * argv[]) {
    char word[LINESIZE];
    
    while (get_word("Enter an ID: ", word, 10)) {
        if (is_valid_id(word)) {
            word[0] = tolower(word[0]);
            fprintf(stderr, "%s\n", word);
        }
    }
    return 0;
}
