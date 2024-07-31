#include <stdio.h>
#include <string.h>
#include <ctype.h>

void monoalphabeticSubstitution(char *plaintext, char *ciphertext, const char *mapping) {
    int i;

    for (i = 0; plaintext[i] != '\0'; ++i) {
        if (isalpha(plaintext[i])) {
            ciphertext[i] = islower(plaintext[i]) ? tolower(mapping[plaintext[i] - 'a']) : toupper(mapping[plaintext[i] - 'A']);
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[i] = '\0';
}

int main() {
    char plaintext[100], ciphertext[100];
    const char *mapping = "DEFGHIJKLMNOPQRSTUVWXYZABC"; // Example mapping

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    monoalphabeticSubstitution(plaintext, ciphertext, mapping);

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}

