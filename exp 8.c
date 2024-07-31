#include <stdio.h>
#include <string.h>
int main() 
{
	int i,j;
    char plain[] = "abcdefghijklmnopqrstuvwxyz";
    char cipher[] = "CIPHERABDFGJKLMNOQSTUVWXYZ";
    char text[] = "hello";
    for(i = 0; i < strlen(text); i++)
        for (j = 0; j < 26; j++)
            if (text[i] == plain[j]) 
           {
                text[i] = cipher[j];
                break;
            }
    printf("Ciphered text: %s\n", text);
    return 0;
}
