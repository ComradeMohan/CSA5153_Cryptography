#include <stdio.h>
#include <ctype.h>

char encryptAffine(char message, int a, int b) {
    if (!isalpha(message)) {
        return message; 
    }

    int newAscii = (toupper(message) - 'A') * a + b; 
    newAscii = (newAscii % 26 + 26) % 26; 
    return (char)(newAscii + 'A'); 
}

char decryptAffine(char message, int a, int b) {
    int inverse_a = modular_inverse(a, 26); 
    if (inverse_a == -1) {
        return message; 
    }

    int newAscii = (message - 'A' - b) * inverse_a % 26; 
    newAscii = (newAscii % 26 + 26) % 26; 
    return (char)(newAscii + 'A'); 
}


int modular_inverse(int a, int m) {
    
    
    return -1; 
}

int main() {
	int i;
    char message[] = "This is a secret message.";
    int a = 3;  
    int b = 5;

    printf("Original message: %s\n", message);

    printf("Encrypted message: ");
    for (i = 0; message[i] != '\0'; i++) {
        printf("%c", encryptAffine(message[i], a, b));
    }
    printf("\n");

    printf("Decrypted message: ");
    for ( i = 0; message[i] != '\0'; i++) {
        printf("%c", decryptAffine(message[i], a, b));
    }
    printf("\n");

    return 0;
}

