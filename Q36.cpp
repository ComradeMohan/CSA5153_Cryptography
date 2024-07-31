#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void affine_encrypt(char *plaintext, int a, int b, char *ciphertext) {
    int len = strlen(plaintext);
    for (int i = 0; i < len; i++) {
        ciphertext[i] = ((a * (plaintext[i] - 'A') + b) % 26) + 'A';
    }
    ciphertext[len] = '\0';
}

int main() {
    char plaintext[] = "HELLO";
    char ciphertext[6];
    int a = 5, b = 8;

    if (gcd(a, 26) != 1) {
        printf("Error: 'a' must be coprime with 26\n");
        return 1;
    }

    affine_encrypt(plaintext, a, b, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
