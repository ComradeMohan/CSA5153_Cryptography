#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define BLOCK_SIZE 16 // 128 bits for this example

void print_hex(const char *label, uint8_t *data, int len) {
    printf("%s: ", label);
    for (int i = 0; i < len; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

void left_shift(uint8_t *input, uint8_t *output, int len) {
    int carry = 0;
    for (int i = len - 1; i >= 0; i--) {
        int next_carry = (input[i] & 0x80) ? 1 : 0;
        output[i] = (input[i] << 1) | carry;
        carry = next_carry;
    }
}

void xor_with_constant(uint8_t *data, int len, uint8_t constant) {
    data[len - 1] ^= constant;
}

void generate_subkeys(uint8_t *key, uint8_t *k1, uint8_t *k2, int block_size) {
    uint8_t L[BLOCK_SIZE] = {0}; // Assuming AES(block_size = 128)
    uint8_t Rb;

    // Rb value for block size
    if (block_size == 8) {
        Rb = 0x1B; // for 64 bits
    } else {
        Rb = 0x87; // for 128 bits
    }

    // AES encryption of zero block (this is a placeholder, replace with actual AES function)
    // AES_encrypt_zero_block(key, L);

    // Simulating AES with zero block for this example
    memset(L, 0xAB, block_size); // Placeholder for AES encryption result

    // Generate K1
    left_shift(L, k1, block_size);
    if (L[0] & 0x80) {
        xor_with_constant(k1, block_size, Rb);
    }

    // Generate K2
    left_shift(k1, k2, block_size);
    if (k1[0] & 0x80) {
        xor_with_constant(k2, block_size, Rb);
    }
}

int main() {
    uint8_t key[BLOCK_SIZE] = {0}; // Example key
    uint8_t k1[BLOCK_SIZE];
    uint8_t k2[BLOCK_SIZE];

    generate_subkeys(key, k1, k2, BLOCK_SIZE);

    print_hex("K1", k1, BLOCK_SIZE);
    print_hex("K2", k2, BLOCK_SIZE);

    return 0;
}
