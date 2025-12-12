#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
a - 97
...
z - 122

A - 65
...
Z - 90
*/


char *input_string() {
    char *str = (char *)malloc(100 * sizeof(char));

    fgets(str, 100, stdin);

    return str;
}


void caesar_cipher(char *text, int shift) {
    int i = 0;
    //printf("t %d %c\n", text[i], text[i]);
    while (text[i] != '\n') {

        int ascii = text[i];

        if (97 <= ascii && ascii <= 122 && 122 < ascii + shift) {
            //printf("small %d %d\n", ascii, 96 + (ascii + shift - 122));
            ascii = 96 + (ascii + shift - 122);
        }
        else if (65 <= ascii && ascii <= 90 && 90 < ascii + shift) {
            //printf("CAP %d %d\n", ascii, 64 + (ascii + shift - 90));
            ascii = 64 + (ascii + shift - 90);
        }
        else {
            ascii += shift;
        }

        printf("%c", ascii);
        i++;
    }
    printf("\n");
}


void caesar_decipher(char *text, int shift) {
    int i = 0;
    while (text[i] != '\n') {
        int ascii = text[i];

        if (97 <= ascii && ascii <= 122 && ascii - shift < 97) {
            //printf("small %d %d\n", ascii, 123 - (97 - (ascii - shift)));
            ascii = 123 - (97 - (ascii - shift));
        }
        else if (65 <= ascii && ascii <= 90 && ascii - shift < 65) {
            //printf("CAP %d %d\n", ascii, 91 - (65 - (ascii - shift)));
            ascii = 91 - (65 - (ascii - shift));
        }
        else {
            ascii -= shift;
        }

        printf("%c", ascii);
        i++;
    }
    printf("\n");
}


int main() {
    printf("string (<100) >>> ");
    char *str = input_string();
    
    int shift;
    printf("shift >>> ");
    scanf("%d%*c", &shift);

    char choice;
    printf("cipher/decipher? (c/d) >>> ");
    scanf("%c", &choice);

    switch (choice) {
        case 'c':
            caesar_cipher(str, shift);
            break;
        case 'd':
            caesar_decipher(str, shift);
            break;
    }
    
    return 0;
}