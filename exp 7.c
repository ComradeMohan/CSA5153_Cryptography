#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 5
void create_table(char keyword[], char table[SIZE][SIZE]) {
    int i, j, k = 0;
    char alphabet[26] = "abcdefghiklmnopqrstuvwxyz";
    int flag[26] = {0};
    for (i = 0; i < strlen(keyword); i++) {
        char c = tolower(keyword[i]);
        if (c == 'j') c = 'i';
        if (!flag[c - 'a']) {
            table[k / SIZE][k % SIZE] = c;
            flag[c - 'a'] = 1;
            k++;
        }
    }
    for (i = 0; i < 26; i++) {
        if (!flag[i]) {
            table[k / SIZE][k % SIZE] = 'a' + i;
            k++;
        }
    }
}
void playfair_cipher(char table[SIZE][SIZE], char plaintext[], char ciphertext[]) {
    int i, j, k = 0;
    int row1, col1, row2, col2;
    for (i = 0; i < strlen(plaintext); i += 2) {
        char c1 = tolower(plaintext[i]);
        char c2 = tolower(plaintext[i + 1]);
        if (c1 == 'j') c1 = 'i';
        if (c2 == 'j') c2 = 'i';
        for (j = 0; j < SIZE; j++) {
            for (k = 0; k < SIZE; k++) {
                if (table[j][k] == c1) {
                    row1 = j;
                    col1 = k;
                }
                if (table[j][k] == c2) {
                    row2 = j;
                    col2 = k;
                }
            }
        }
        if (row1 == row2) {
            ciphertext[i] = table[row1][(col1 + 1) % SIZE];
            ciphertext[i + 1] = table[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) {
            ciphertext[i] = table[(row1 + 1) % SIZE][col1];
            ciphertext[i + 1] = table[(row2 + 1) % SIZE][col2];
        } else {
            ciphertext[i] = table[row1][col2];
            ciphertext[i + 1] = table[row2][col1];
        }
    }
    ciphertext[strlen(plaintext)] = '\0';
}
int main() 
{
    char keyword[20], plaintext[100], ciphertext[100];
    char table[SIZE][SIZE];
    printf("Enter keyword: ");
    scanf("%s", keyword);
    printf("Enter plaintext: ");
    scanf("%s", plaintext);
    create_table(keyword, table);
    playfair_cipher(table, plaintext, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);
    return 0;
}
