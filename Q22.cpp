#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 8

void xor_blocks(unsigned char *block1, unsigned char *block2, unsigned char *result) {
    for (int i = 0; i < BLOCK_SIZE; ++i) {
        result[i] = block1[i] ^ block2[i];
    }
}

void sdes_encrypt(unsigned char *plaintext, unsigned char *key, unsigned char *ciphertext) {
    // Placeholder for S-DES encryption function
    // Implement S-DES encryption here
}

void sdes_decrypt(unsigned char *ciphertext, unsigned char *key, unsigned char *plaintext) {
    // Placeholder for S-DES decryption function
    // Implement S-DES decryption here
}

void cbc_encrypt(unsigned char *plaintext, int length, unsigned char *key, unsigned char *iv, unsigned char *ciphertext) {
    unsigned char block[BLOCK_SIZE];
    unsigned char previous_block[BLOCK_SIZE];
    memcpy(previous_block, iv, BLOCK_SIZE);

    for (int i = 0; i < length; i += BLOCK_SIZE) {
        xor_blocks(plaintext + i, previous_block, block);
        sdes_encrypt(block, key, ciphertext + i);
        memcpy(previous_block, ciphertext + i, BLOCK_SIZE);
    }
}

void cbc_decrypt(unsigned char *ciphertext, int length, unsigned char *key, unsigned char *iv, unsigned char *plaintext) {
    unsigned char block[BLOCK_SIZE];
    unsigned char previous_block[BLOCK_SIZE];
    unsigned char decrypted_block[BLOCK_SIZE];
    memcpy(previous_block, iv, BLOCK_SIZE);

    for (int i = 0; i < length; i += BLOCK_SIZE) {
        sdes_decrypt(ciphertext + i, key, decrypted_block);
        xor_blocks(decrypted_block, previous_block, plaintext + i);
        memcpy(previous_block, ciphertext + i, BLOCK_SIZE);
    }
}

int main() {
    unsigned char key[10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1}; // Binary key 01111 11101
    unsigned char iv[BLOCK_SIZE] = {1, 0, 1, 0, 1, 0, 1, 0}; // Binary IV 1010 1010
    unsigned char plaintext[BLOCK_SIZE] = {0, 0, 0, 1, 0, 0, 1, 1}; // Binary plaintext 0000 0001 0010 0011
    unsigned char ciphertext[BLOCK_SIZE];
    unsigned char decryptedtext[BLOCK_SIZE];

    printf("CBC Mode Encryption and Decryption using S-DES\n");

    // Encrypt
    cbc_encrypt(plaintext, BLOCK_SIZE, key, iv, ciphertext);
    printf("Ciphertext: ");
    for (int i = 0; i < BLOCK_SIZE; ++i) {
        printf("%d", ciphertext[i]);
    }
    printf("\n");

    // Decrypt
    cbc_decrypt(ciphertext, BLOCK_SIZE, key, iv, decryptedtext);
    printf("Decrypted Text: ");
    for (int i = 0; i < BLOCK_SIZE; ++i) {
        printf("%d", decryptedtext[i]);
    }
   
