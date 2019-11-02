#include <stdio.h>
#include <ctype.h>
#include <string.h>

void squeeze_spaces(void) {
    int c;
    int isLastCharASpace = 0;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t') {
            /* continue if the last char is a space */
            if (isLastCharASpace)
                continue;
            else
                isLastCharASpace = 1;
            
            /* convert a tab to a space */
            if (c == '\t')
                c = ' ';
        } else {
            isLastCharASpace = 0;
        }
        putchar(c);
    }
}

void format_words(void) {
    int c;
    int shouldUppercase = 1;
    
    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            c = shouldUppercase ? toupper(c) : tolower(c);
            shouldUppercase = 0;
        } else if (isspace(c) || c == '"') {
            shouldUppercase = 1;
        }
        putchar(c);
    }
}

int main(int argc, const char * argv[]) {
    if (argc == 1) {
        printf("Missing flag!\n-s - squeeze spaces\n-f - format words\n");
        return 1;
    }
    
    if (strcmp(argv[1], "-s") == 0) {
        squeeze_spaces();
    } else if (strcmp(argv[1], "-f") == 0) {
        format_words();
    }
    
    return 0;
}
