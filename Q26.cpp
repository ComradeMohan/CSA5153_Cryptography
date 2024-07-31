#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    srand(time(0));
    int p, q, n, e, d;

    // Generate new p and q
    p = rand() % 100 + 50; // Random primes for simplicity
    q = rand() % 100 + 50;
    n = p * q;

    int phi = (p - 1) * (q - 1);
    e = 31; // Choose a new e
    d = modInverse(e, phi);

    printf("New public key: e = %d, n = %d\n", e, n);
    printf("New private key: d = %d\n", d);
    return 0;
}
