#include <stdio.h>
#include <string.h>

#define max(a,b) ((a) > (b) ? (a) : (b))
#define CHECK(X) printf("%s...%s\n", (X) ? "passed" : "FAILED", #X)

int *arr_last_max(const int *a, size_t n) {
    const int *p = a;
    size_t i;
    for (i = 1; i < n; i++)
        if (*p <= *(a + i))
            p = a + i;
    return (int *) p;
}

size_t str_replace_all(char *s, int oldc, int newc) {
    char *p;
    size_t nReplacements = 0;
    for (p = s; *p != '\0'; p++)
        if (*p == oldc) {
            *p = newc;
            nReplacements++;
        }
    return nReplacements;
}

int arr_max(const int *a, size_t n) {
    if (n == 1)
        return *a;
    return max(a[n - 1], arr_max(a, n - 1));
}

char *str_find_last(const char *s, int c) {
    if (*s == '\0')
        return NULL;
    
    char *p = str_find_last(s + 1, c);
    
    if (p == NULL && *s == c)
        p = (char *) s;

    return p;
}

int main(int argc, const char * argv[]) {
    int a[] = {7,1,1,2,1,1,7};
    int b[] = {2,3,3,1,2};
    int *lastMax;
    char s1[] = "hello";
    char s2[] = "world";
    size_t nReps;
    char *lastChar;
    
    lastMax = arr_last_max(a, 7);
    CHECK(lastMax == a + 6);
    CHECK(*lastMax == 7);
    
    lastMax = arr_last_max(b, 5);
    CHECK(lastMax == b + 2);
    CHECK(*lastMax == 3);
    
    nReps = str_replace_all(s1, 'l', 'z');
    CHECK(strcmp(s1, "hezzo") == 0);
    CHECK(nReps == 2);
    
    nReps = str_replace_all(s2, 'u', 'v');
    CHECK(strcmp(s2, "world") == 0);
    CHECK(nReps == 0);
    
    CHECK(arr_max(a, 7) == 7);
    CHECK(arr_max(b, 5) == 3);
    
    lastChar = str_find_last(s1, 'z');
    CHECK(lastChar == s1 + 3);
    CHECK(*lastChar == 'z');
    
    lastChar = str_find_last(s2, 'w');
    CHECK(lastChar == s2);
    CHECK(*lastChar == 'w');
    
    return 0;
}
