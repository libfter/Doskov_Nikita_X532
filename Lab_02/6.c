#include <stdio.h>

int main() {
	//выводит наименьший делитель (n) от числа (a)
	for (int a=0; a<100; a++) {
		for (int s=0, n=2; n<a; n++) {
			if (a%n==0) {
				s = 1;
				printf("a = %d, s = %d, n = %d\n", a, s, n);
				break;
			}
		}
	}
	
	return 0;
}
