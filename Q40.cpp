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

void substitute(char *ciphertext, char *key, char *plaintext) {
    int len = strlen(ciphertext);
    for (int i = 0; i < len; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            plaintext[i] = key[ciphertext[i] - 'A'];
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[len] = '\0';
}

void sort_frequencies(int *freq, char *letters) {
    for (int i = 0; i < 26; i++) {
        letters[i] = 'A' + i;
    }

    for (int i = 0; i < 25; i++) {
        for (int j = i + 1; j < 26; j++) {
            if (freq[i] < freq[j]) {
                int temp_freq = freq[i];
                freq[i] = freq[j];
                freq[j] = temp_freq;

                char temp_letter = letters[i];
                letters[i] = letters[j];
                letters[j] = temp_letter;
            }
        }
    }
}

void perform_attack(char *ciphertext) {
    int freq[26] = {0};
    char letters[26];
    char plaintext[256];
    char keys[10][26] = {
        "ETAOINSHRDLCUMWFGYPBVKJXQZ",
        "ETAOINSHRDLCUMWFGYPBVJZKXQ",
        "ETAOINSHRDLCUMWFGYPBZVKXJQ",
        "ETAOINSHRDLCUMWFGYPBVKJQXZ",
        "ETAOINSHRDLCUMWFGYPBZVJXKQ",
        "ETAOINSHRDLCUMWFGYPBVJXKQZ",
        "ETAOINSHRDLCUMWFGYPBVZKJXQ",
        "ETAOINSHRDLCUMWFGYPBVJKXQZ",
        "ETAOINSHRDLCUMWFGYPBVKJXZQ",
        "ETAOINSHRDLCUMWFGYPBVJKQXZ"
    };

    frequency_analysis(ciphertext, freq);
    sort_frequencies(freq, letters);

    for (int i = 0; i < 10; i++) {
        char key[26];
        for (int j = 0; j < 26; j++) {
            key[letters[j] - 'A'] = keys[i][j];
        }
        substitute(ciphertext, key, plaintext);
        printf("Possible plaintext %2d: %s\n", i + 1, plaintext);
    }
}

int main() {
    char ciphertext[] = "QEB NRFZH YOLTK CLU GRJMP LSBO QEB IXWV ALD";

    perform_attack(ciphertext);

    return 0;
}
