#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

void handleErrors() {
    fprintf(stderr, "An error occurred\n");
    exit(1);
}

void printData(const char *title, const void *data, int len) {
    printf("%s: ", title);
    const unsigned char *p = (const unsigned char*)data;
    for (int i = 0; i < len; ++i) {
        printf("%02x ", *p++);
    }
    printf("\n");
}

void padData(unsigned char *data, int *len, int blockSize) {
    int padding = blockSize - (*len % blockSize);
    memset(data + *len, padding, padding);
    *len += padding;
}

int main() {
    // Key and IV setup
    unsigned char key[AES_BLOCK_SIZE];
    unsigned char iv[AES_BLOCK_SIZE];

    if (!RAND_bytes(key, sizeof(key)) || !RAND_bytes(iv, sizeof(iv))) {
        handleErrors();
    }

    // Example plaintext
    unsigned char plaintext[] = "This is a test message to demonstrate ECB, CBC, and CFB modes.";
    int plaintext_len = strlen((char *)plaintext);

    // Pad the plaintext to ensure it's a multiple of the block size
    int blockSize = AES_BLOCK_SIZE;
    int padded_len = plaintext_len;
    padData(plaintext, &padded_len, blockSize);

    // Buffers for ciphertext and decrypted text
    unsigned char ciphertext[128];
    unsigned char decryptedtext[128];

    // ECB Mode
    AES_KEY enc_key, dec_key;
    AES_set_encrypt_key(key, 128, &enc_key);
    AES_set_decrypt_key(key, 128, &dec_key);

    printf("ECB Mode:\n");
    for (int i = 0; i < padded_len; i += blockSize) {
        AES_ecb_encrypt(plaintext + i, ciphertext + i, &enc_key, AES_ENCRYPT);
    }
    printData("Ciphertext", ciphertext, padded_len);

    for (int i = 0; i < padded_len; i += blockSize) {
        AES_ecb_encrypt(ciphertext + i, decryptedtext + i, &dec_key, AES_DECRYPT);
    }
    printData("Decrypted Text", decryptedtext, padded_len);

    // CBC Mode
    memset(ciphertext, 0, sizeof(ciphertext));
    memset(decryptedtext, 0, sizeof(decryptedtext));
    AES_cbc_encrypt(plaintext, ciphertext, padded_len, &enc_key, iv, AES_ENCRYPT);
    printData("Ciphertext", ciphertext, padded_len);

    // Reset IV for decryption
    AES_cbc_encrypt(ciphertext, decryptedtext, padded_len, &dec_key, iv, AES_DECRYPT);
    printData("Decrypted Text", decryptedtext, padded_len);

    // CFB Mode
    memset(ciphertext, 0, sizeof(ciphertext));
    memset(decryptedtext, 0, sizeof(decryptedtext));
    AES_cfb128_encrypt(plaintext, ciphertext, padded_len, &enc_key, iv, AES_ENCRYPT);
    printData("Ciphertext", ciphertext, padded_len);

    // Reset IV for decryption
    AES_cfb128_encrypt(ciphertext, decryptedtext, padded_len, &dec_key, iv, AES_DECRYPT);
    printData("Decrypted Text", decryptedtext, padded_len);

    return 0;
}
