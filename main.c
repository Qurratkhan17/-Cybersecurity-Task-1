//
//  main.c
//  task1 program
//
//  Created by Qurrat ULAIN KHAN on 17/09/25.
//


#include <stdio.h>
#include <ctype.h>

void caesarCipher(char text[], int shift, char mode) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';

            if (mode == 'e') { // Encryption
                text[i] = (ch - base + shift) % 26 + base;
            } else if (mode == 'd') { // Decryption
                text[i] = (ch - base - shift + 26) % 26 + base;
            }
        }
    }
}

int main(void) {
    char message[1000];
    int shift;
    char choice;

    printf("=== Caesar Cipher Program ===\n");
    printf("Enter your message: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter shift value (e.g., 3): ");
    scanf("%d", &shift);

    printf("Do you want to Encrypt or Decrypt? (e/d): ");
    scanf(" %c", &choice);

    if (choice == 'e') {
        caesarCipher(message, shift, 'e');
        printf("Encrypted Message: %s\n", message);
    } else if (choice == 'd') {
        caesarCipher(message, shift, 'd');
        printf("Decrypted Message: %s\n", message);
    } else {
        printf("Invalid choice! Please enter 'e' or 'd'.\n");
    }

    return 0;
}
