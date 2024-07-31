#include <stdio.h>
#include <stdlib.h>

// Function to compute the GCD
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Extended Euclidean Algorithm to find the multiplicative inverse
int extended_euclidean(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1;
    int gcd = extended_euclidean(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

int mod_inverse(int a, int m) {
    int x, y;
    int g = extended_euclidean(a, m, &x, &y);
    if (g != 1) {
        printf("Inverse doesn't exist\n");
        return -1;
    } else {
        int res = (x % m + m) % m;
        return res;
    }
}

int main() {
    int e = 31;
    int n = 3599;
    int p, q;

    // Finding p and q
    for (p = 2; p < n; ++p) {
        if (n % p == 0) {
            q = n / p;
            if (n == p * q) break;
        }
    }

    int phi = (p - 1) * (q - 1);

    int d = mod_inverse(e, phi);

    if (d != -1) {
        printf("Private key: %d\n", d);
    }

    return 0;
}
