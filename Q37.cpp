#include <stdio.h>
#include <string.h>

void frequency_analysis(char *ciphertext) {
    int freq[26] = {0};
    int len = strlen(ciphertext);

    for (int i = 0; i < len; i++) {
        freq[ciphertext[i] - 'A']++;
    }

    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", 'A' + i, freq[i]);
    }
}ssint main() {
    char ciphertext[] = "QEB NRFZH YOLTK CLU GRJMP LSBO QEB IXWV ALD";

    frequency_analysis(ciphertext);

    return 0;
}
