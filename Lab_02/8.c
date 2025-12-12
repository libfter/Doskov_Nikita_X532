#include <stdio.h>

int main() {
	//(s) = факториал от (n)
	for (int n=0; n<10; n++) {
		int s = 1;
		for (int i=1; i<=n; i++) {
			s = s * i;
		}
		printf("n = %d, s = %d\n", n, s);
	}
	return 0;
}
