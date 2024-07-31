#include <stdio.h>
#include <string.h>

void xorBlocks(char *block1, char *block2, char *out, int blockSize) {
    for (int i = 0; i < blockSize; ++i) {
        out[i] = block1[i] ^ block2[i];
    }
}

int main() {
    char K[] = "secretkey";
    char X[] = "message";
    char T[8];
    char X2[8];
    int blockSize = 8;

    // Compute CBC MAC
    xorBlocks(K, X, T, blockSize);

    // Compute CBC MAC for two-block message
    xorBlocks(X, T, X2, blockSize);
    xorBlocks(K, X2, T, blockSize);

    // Print results
    printf("MAC for one-block message: %s\n", T);
    printf("MAC for two-block message: %s\n", T);
    return 0;
}
