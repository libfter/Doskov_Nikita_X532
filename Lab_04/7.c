#include <stdio.h>

int main() {
    int a;
    printf("a >>> ");
    scanf("%d", &a);
    printf("%b\n", a);

    int b = 0, k = 0;
    while (b != 1) {
        b = a & 1;
        a = a >> 1;
        k -= 1;
    }
    
    printf("a[%d] == 1\n", k);
}