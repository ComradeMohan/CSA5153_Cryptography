#include <stdio.h>
#include <math.h>

int main() {
    int a = 5, q = 23;
    int xA = 6, xB = 15;

    int A = pow(a, xA) % q;
    int B = pow(a, xB) % q;

    int keyA = pow(B, xA) % q;
    int keyB = pow(A, xB) % q;

    printf("Shared key (Alice): %d\n", keyA);
    printf("Shared key (Bob): %d\n", keyB);
    return 0;
}
