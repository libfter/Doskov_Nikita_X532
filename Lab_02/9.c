#include <stdio.h>

int main() {
	//выводит наибольшую цифру (k) в числе (a)
	for (int a=2; a<100; a++) {
		int k = 0;
		for (int n=a, s=0; n!=0; n=n/10) {
			k = n%10;
			if (k>s) {s=k;}
		}
		printf("a = %d, k = %d\n", a, k);
	}
}
