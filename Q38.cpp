#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3 // Assuming a 3x3 key matrix

void hill_encrypt(char *plaintext, int key[N][N], char *ciphertext) {
    int len = strlen(plaintext);
    for (int i = 0; i < len; i += N) {
        for (int j = 0; j < N; j++) {
            ciphertext[i + j] = 0;
            for (int k = 0; k < N; k++) {
                ciphertext[i + j] += key[j][k] * (plaintext[i + k] - 'A');
            }
            ciphertext[i + j] = (ciphertext[i + j] % 26) + 'A';
        }
    }
    ciphertext[len] = '\0';
}

int main() {
    char plaintext[] = "ACT";
    char ciphertext[4];
    int key[N][N] = {
        {6, 24, 1},
        {13, 16, 10},
        {20, 17, 15}
    };

    hill_encrypt(plaintext, key, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
