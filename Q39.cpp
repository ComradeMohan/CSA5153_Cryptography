#include <stdio.h>
#include <string.h>

void frequency_analysis(char *ciphertext, int *freq) {
    int len = strlen(ciphertext);
    for (int i = 0; i < len; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            freq[ciphertext[i] - 'A']++;
        }
    }
}

void decrypt_additive_cipher(char *ciphertext, int key, char *plaintext) {
    int len = strlen(ciphertext);
    for (int i = 0; i < len; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            plaintext[i] = ((ciphertext[i] - 'A' - key + 26) % 26) + 'A';
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[len] = '\0';
}

void perform_attack(char *ciphertext) {
    int freq[26] = {0};
    char plaintext[256];
    int most_frequent_letter = 'E' - 'A'; // Assume 'E' is the most frequent letter in English

    frequency_analysis(ciphertext, freq);

    for (int i = 0; i < 26; i++) {
        int key = (i - most_frequent_letter + 26) % 26;
        decrypt_additive_cipher(ciphertext, key, plaintext);
        printf("Key: %2d, Plaintext: %s\n", key, plaintext);
    }
}

int main() {
    char ciphertext[] = "LIPPS ASVPH";

    perform_attack(ciphertext);

    return 0;
}
