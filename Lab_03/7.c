#include <stdio.h>

/* *****
 *  ****
 *   ***
 *    **
 *     * */

int main() {
	int n;
	printf("кол-во строк - ");
	scanf("%d", &n);
	printf("\n");
	
	int a = n;
	for(a; a>0; a--) {
		int b = n-a;
		int c = n-b;

		for(b; b>0; b--) {
			printf(" ");
		}
		for(c; c>0; c--) {
			printf("*");
		}
		printf("\n");
	}
}
