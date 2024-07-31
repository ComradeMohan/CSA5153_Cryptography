#include <stdio.h>

int main() {
    // Example to illustrate the insecurity
    char message[] = "HELLO";
    int encrypted_message[5];

    int e = 31, n = 3599;
    for (int i = 0; i < 5; ++i) {
        encrypted_message[i] = ((message[i] - 'A') * (message[i] - 'A')) % n;
    }

    // Print encrypted message
    for (int i = 0; i < 5; ++i) {
        printf("%d ", encrypted_message[i]);
    }
    printf("\n");
    return 0;
}
