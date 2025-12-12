#include <stdio.h>

int main() {
	//определяет, простое число или нет (flag)	
	for (int a=2;a<100;a++) {
		int n = 2, flag = 0;
		while (a%n!=0) {
			n++;
			if (n==a) {
				flag = 1;
				break;
			}
		}
		printf("a = %d, flag = %d\n", a, flag);
	}
}
