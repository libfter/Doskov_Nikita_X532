#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
input
1 23 456 7890

reverse all string
0987 654 32 1

reverse each word
7890 456 23 1
*/

char *input_string() {
    char *str = (char *)malloc(100 * sizeof(char));

    fgets(str, 100, stdin);

    return str;
}


void reverse_string(char *str, int start, int end) {
    int len = strlen(str)-1;

    while (start < end) {
        //printf("\n%c - %c\n", str[start], str[end]);
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}


char *reverse_words(char *str) {
    int len = strlen(str)-2;

    //reverse all string
    reverse_string(str, 0, len);

    //reverse each word
    int start = 0;
    int end = 0;

    while (str[end]) {
        if (str[end] == ' ') {
            reverse_string(str, start, end-1);
            start = end + 1;
        }
        end++;
    }

    //reverse last word
    reverse_string(str, start, end-2);

    return str;
}


int main() {
    printf("string (<100) >>> ");
    char *str = input_string();

    str = reverse_words(str);

    printf("%s", str);
    
    free(str);
    
    return 0;
}