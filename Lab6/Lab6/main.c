#include <stdio.h>

#define CHECK(X) printf("%s...%s\n", (X) ? "passed" : "FAILED", #X)

void min_max(const int a[], size_t n, int *pmin, int *pmax) {
    size_t i;
    *pmin = a[0];
    *pmax = a[0];
    for (i = 1; i < n; i++) {
        if (*pmin > a[i])
            *pmin = a[i];
        if (*pmax < a[i])
            *pmax = a[i];
    }
}

unsigned num_digits(unsigned long n) {
    unsigned count = 0;
    while (n != 0) {
        count++;
        n /= 10;
    }
    return count;
}

unsigned long reverse(unsigned long n) {
    unsigned long result = 0;
    while (n != 0) {
        result *= 10;
        result += n % 10;
        n /= 10;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    int min = 0;
    int max = 0;
    int a[] = {4, 3, 5, 7, 2};
    int b[] = {-1, 3, 20, -5, 2};
    unsigned long n = 123456789;
    unsigned long m = 97531;
    
    min_max(a, 5, &min, &max);
    CHECK(min == 2);
    CHECK(max == 7);
    
    min_max(b, 5, &min, &max);
    CHECK(min == -5);
    CHECK(max == 20);
    
    CHECK(num_digits(n) == 9);
    CHECK(num_digits(m) == 5);
    
    CHECK(reverse(n) == 987654321);
    CHECK(reverse(m) == 13579);
    
    return 0;
}
