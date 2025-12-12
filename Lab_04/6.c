#include <stdio.h>

int main() {
    int a;
    printf("a >>> ");
    scanf("%d", &a);

    int k;
    printf("k >>> ");
    scanf("%d", &k);

    int l = -1;
    for (int i = 0; i < k; i++) {
        l = (a & 0x80000000) >> 31;
        a = a << 1;
        a += l;      
    }

    printf("%b\n", a);
}