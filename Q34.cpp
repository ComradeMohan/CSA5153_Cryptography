#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define BLOCK_SIZE 8 // 64 bits for this example

void pad(uint8_t *input, uint8_t *padded, int len) {
    int pad_len = BLOCK_SIZE - (len % BLOCK_SIZE);
    memcpy(padded, input, len);
    padded[len] = 0x80; // Padding starts with 1 bit followed by zeros
    for (int i = len + 1; i < len + pad_len; i++) {
        padded[i] = 0x00;
    }
}

void print_hex(const char *label, uint8_t *data, int len) {
    printf("%s: ", label);
    for (int i = 0; i < len; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

int main() {
    uint8_t plaintext[16] = "Hello, world!";
    uint8_t padded[24]; // Larger than plaintext to accommodate padding

    int plaintext_len = strlen((char *)plaintext);
    pad(plaintext, padded, plaintext_len);
    print_hex("Padded plaintext", padded, 24);

    return 0;
}
