#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void encrypt_vigenere(char *plaintext, int *key, char *ciphertext) {
    int len = strlen(plaintext);
    for (int i = 0; i < len; i++) {
        ciphertext[i] = ((plaintext[i] - 'A' + key[i]) % 26) + 'A';
    }
    ciphertext[len] = '\0';
}

void generate_random_key(int *key, int len) {
    for (int i = 0; i < len; i++) {
        key[i] = rand() % 26;
    }
}

int main() {
    char plaintext[] = "HELLOWORLD";
    int key[10];
    char ciphertext[11];

    srand(time(NULL));
    generate_random_key(key, 10);

    encrypt_vigenere(plaintext, key, ciphertext);

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
