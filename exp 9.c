#include <stdio.h>
#include <string.h>
#include <ctype.h>
char getBigramKey(char keySquare[][5], char c1, char c2);
void decryptPlayfair(char message[], char keySquare[][5]);
int main() {
    char message[] = "KXJEY UREBE ZWEHE WRYTU HEYFS KREHE GOYFI WTTTU OLKSY CAJPO BOTEI ZONTX BYBNT GONEY CUZWR GDSON SXBOU YWRHE BAAHY USEDQ";
    char keySquare[5][5];
    decryptPlayfair(message, keySquare);
    printf("Decrypted message: %s\n", message);
    return 0;
}
char getBigramKey(char keySquare[][5], char c1, char c2) {
    int row1 = (int)c1 - 'A';
    int col1 = (int)c2 - 'A';
    return keySquare[row1][col1];
}
void decryptPlayfair(char message[], char keySquare[][5]) {
    int i = 0;
    while (message[i] != '\0') {
        if (!isalpha(message[i]) || !isalpha(message[i + 1])) {
            i++;
            continue;
        }
        char key1 = getBigramKey(keySquare, message[i], message[i + 1]);
        char key2 = getBigramKey(keySquare, message[i + 1], message[i]);
        i += 2;
    }
}

