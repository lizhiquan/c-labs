#include <stdio.h>
#include <ctype.h>

#define CHECK(X) printf("%s...%s\n", (X) ? "passed" : "FAILED", #X)

size_t str_find_last(const char s[], int c) {
    size_t i = 0;
    size_t index = -1;
    for (i = 0; s[i] != '\0'; i++)
        if (s[i] == c)
            index = i;
    return index;
}

size_t str_replace_all(char s[], int oldc, int newc) {
    size_t count = 0;
    size_t i = 0;
    for (i = 0; s[i] != '\0'; i++)
        if (s[i] == oldc) {
            s[i] = newc;
            count++;
        }
    return count;
}

int str_all_alphas(const char s[]) {
    size_t i = 0;
    for (i = 0; s[i] != '\0'; i++)
        if (!isalpha(s[i]))
            return 0;
    return 1;
}

int str_equal(const char s[], const char t[]) {
    size_t i = 0;
    for (i = 0; s[i] != '\0'; i++)
        if (s[i] != t[i])
            return 0;
    if (s[i] != t[i])
        return 0;
    return 1;
}

int main(int argc, const char * argv[]) {
    char s[] = "this is me";
    char t[] = "hello";
    char r[] = "111";
    char v[] = "a1b2c3_";
    
    // str_find_last
    CHECK(str_find_last(s, 's') == 6);
    CHECK(str_find_last(t, 'o') == 4);
    CHECK(str_find_last(s, ' ') == 7);
    CHECK(str_find_last(s, 't') == 0);
    
    // str_replace_all
    CHECK(str_replace_all(s, 't', 'e') == 1);
    CHECK(strcmp(s, "ehis is me") == 0);
    CHECK(str_replace_all(s, 'i', '1') == 2);
    CHECK(strcmp(s, "eh1s 1s me") == 0);
    CHECK(str_replace_all(t, 'a', 'e') == 0);
    CHECK(strcmp(t, "hello") == 0);
    CHECK(str_replace_all(t, 'l', 'i') == 2);
    CHECK(strcmp(t, "heiio") == 0);
    
    // str_all_alphas
    CHECK(str_all_alphas(s) == 0);
    CHECK(str_all_alphas(t) == 1);
    CHECK(str_all_alphas(r) == 0);
    CHECK(str_all_alphas(v) == 0);
    
    // str_equal
    CHECK(str_equal(s, "this is me") == 0);
    CHECK(str_equal(s, "eh1s 1s me") == 1);
    CHECK(str_equal(r, "1111") == 0);
    CHECK(str_equal(r, "1") == 0);
    
    return 0;
}
