#include <stdio.h>

int main() {
	//переворачивает число (a) в (s), убирая незначащие нули
	for (int a=123; a<124; a++) {
		int k=0, s=0;
		for (int n=a; n!=0; n=n/10) {
			k = n%10;
			s = s*10 + k;
		}
		printf("a = %d, k = %d, s = %d\n", a, k, s);
	}
}
