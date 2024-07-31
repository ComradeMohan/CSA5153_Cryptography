#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n = 3599;
    int common_factor = 61; // Known common factor

    int p = gcd(common_factor, n);
    int q = n / p;

    printf("Factors of n: p = %d, q = %d\n", p, q);
    return 0;
}
