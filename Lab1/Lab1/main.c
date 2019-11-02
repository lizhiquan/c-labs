#include <stdio.h>

#define CHECK(X) printf("%s...%s\n", (X) ? "passed" : "FAILED", #X)

size_t arr_count(const int a[], size_t n, int x) {
    size_t i;
    size_t count = 0;
    for (i = 0; i < n; i++)
        if (a[i] == x)
            count++;
    return count;
}

int arr_equal(const int a[], const int b[], size_t n) {
    size_t i;
    for (i = 0; i < n; i++)
        if (a[i] != b[i])
            return 0;
    return 1;
}

int arr_min(const int a[], size_t n) {
    size_t i;
    int min = a[0];
    for (i = 1; i < n; i++)
        if (a[i] < min)
            min = a[i];
    return min;
}

size_t arr_count_min(const int a[], size_t n) {
    size_t i;
    int min = a[0];
    size_t count = 1;
    for (i = 1; i < n; i++)
        if (a[i] < min) {
            min = a[i];
            count = 1;
        } else if (a[i] == min) {
            count++;
        }
    return count;
}

int main(void) {
    int a[] = {2, 5, 2, 4, 2, 7};
    int b[] = {2, 5, 3, 4, 2, 7};
    int c[] = {2, 5, 2, 4, 2, 7};
    int d[] = {7, 3, 5, 6, 4, 9};
    int e[] = {2, 5, 2, 0, 2, 7};
    
    /* Test arr_count */
    CHECK(arr_count(a, 6, 1) == 0);
    CHECK(arr_count(a, 6, 2) == 3);
    CHECK(arr_count(a, 6, 7) == 1);
    CHECK(arr_count(a, 6, 9) == 0);
    
    /* Test arr_equal */
    CHECK(arr_equal(a, b, 6) == 0);
    CHECK(arr_equal(a, c, 6) == 1);
    CHECK(arr_equal(a, b, 2) == 1);
    CHECK(arr_equal(a, d, 6) == 0);
    
    /* Test arr_min */
    CHECK(arr_min(a, 6) == 2);
    CHECK(arr_min(b, 6) == 2);
    CHECK(arr_min(d, 6) == 3);
    CHECK(arr_min(e, 6) == 0);
    
    /* Test arr_count_min */
    CHECK(arr_count_min(a, 6) == 3);
    CHECK(arr_count_min(b, 6) == 2);
    CHECK(arr_count_min(d, 6) == 1);
    CHECK(arr_count_min(e, 6) == 1);
    return 0;
}
