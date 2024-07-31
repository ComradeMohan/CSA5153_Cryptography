#include <stdio.h>
#include <ctype.h>
#include <string.h>

char getBigramKey(char keySquare[][5], char c1, char c2) {
    int row1 = (int)toupper(c1) - 'A';
    int col1 = (int)toupper(c2) - 'A';
    return keySquare[row1][col1];
}

void encryptPlayfair(char message[], char keySquare[][5]) {
    int i = 0;
    while (message[i] != '\0') {
        // Handle repeated letters (insert 'X')
        if (isalpha(message[i]) && isalpha(message[i + 1]) && message[i] == message[i + 1]) {
            message[i + 1] = 'X';
        }

        // Check for valid pairs and handle punctuation/spaces
        if (!isalpha(message[i]) || !isalpha(message[i + 1])) {
            i++;
            continue;
        }

        char key1 = getBigramKey(keySquare, message[i], message[i + 1]);
        char key2 = getBigramKey(keySquare, message[i + 1], message[i + 1]); // Use same char for repeated letters

        // Handle same row/column cases (shift positions)
        if (key1 == key2) {
            if (key1 == 'Z') {
                key1 = 'A';
            } else {
                key1++;
            }
            if (key2 == 'Z') {
                key2 = 'A';
            } else {
                key2++;
            }
        }

        // Replace message characters with bigram keys
        message[i] = key1;
        message[i + 1] = key2;

        i += 2;
    }
}

int main() {
    char message[] = "Must see you over Cadogan West. Coming at once.";
    char keySquare[5][5] = {
        {'M', 'F', 'H', 'I', 'J'},
        {'K', 'U', 'N', 'O', 'P'},
        {'Q', 'Z', 'V', 'W', 'X'},
        {'Y', 'E', 'L', 'A', 'R'},
        {'G', 'D', 'S', 'T', 'B'}
    };

    encryptPlayfair(message, keySquare);

    printf("Encrypted message: %s\n", message);

    return 0;
}

