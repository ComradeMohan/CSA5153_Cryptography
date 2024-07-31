#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 8

void sdes_encrypt(unsigned char *plaintext, unsigned char *key, unsigned char *ciphertext) {
    // Placeholder for S-DES encryption function
    // Implement S-DES encryption here
}

void xor_blocks(unsigned char *block1, unsigned char *block2, unsigned char *result) {
    for (int i = 0; i < BLOCK_SIZE; ++i) {
        result[i] = block1[i] ^ block2[i];
    }
}

void counter_mode_encrypt(unsigned char *plaintext, int length, unsigned char *key, unsigned char *counter, unsigned char *ciphertext) {
    unsigned char encrypted_counter[BLOCK_SIZE];
    unsigned char block[BLOCK_SIZE];

    for (int i = 0; i < length; i += BLOCK_SIZE) {
        sdes_encrypt(counter, key, encrypted_counter);
        xor_blocks(plaintext + i, encrypted_counter, block);
        memcpy(ciphertext + i, block, BLOCK_SIZE);
        
        // Increment counter
        for (int j = BLOCK_SIZE - 1; j >= 0; --j) {
            if (++counter[j] != 0) break;
        }
    }
}

void counter_mode_decrypt(unsigned char *ciphertext, int length, unsigned char *key, unsigned char *counter, unsigned char *plaintext) {
    // Decryption is same as encryption in counter mode
    counter_mode_encrypt(ciphertext, length, key, counter, plaintext);
}

int main() {
    unsigned char key[10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1}; // Binary key 01111 11101
    unsigned char counter[BLOCK_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0}; // Binary counter 0000 0000
    unsigned char plaintext[BLOCK_SIZE * 3] = {0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1}; // Binary plaintext 0000 0001 0000 0010 0000 0100
    unsigned char ciphertext[BLOCK_SIZE * 3];
    unsigned char decryptedtext[BLOCK_SIZE * 3];

    printf("Counter Mode Encryption and Decryption using S-DES\n");

    // Encrypt
    counter_mode_encrypt(plaintext, sizeof(plaintext), key, counter, ciphertext);
    printf("Ciphertext: ");
    for (int i = 0; i < sizeof(ciphertext); ++i) {
        printf("%d", ciphertext[i]);
    }
    printf("\n");

    // Reset counter
    memset(counter, 0, BLOCK_SIZE);

    // Decrypt
    counter_mode_decrypt(ciphertext, sizeof(ciphertext), key, counter, decryptedtext);
    printf("Decrypted Text: ");
    for (int i = 0; i < sizeof(decryptedtext); ++i) {
        printf("%d", decryptedtext[i]);
    }
    printf("\n");

    return 0;
}
