#include <stdio.h>
#include <string.h> #memset

int main() {
	int n;
	printf("N - ");
	scanf("%d", &n);
	
	int numbers[n][n];
	memset(numbers, 0, sizeof(numbers));

	int x = 0, y = 0, xi = 0, yi = 0;
	int array_inc[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
	int cur_inc = 0;


	for (int num = 1; num <= n*n; num++) {
		numbers[x][y] = num;

		xi = xi + array_inc[cur_inc][0];
		yi = yi + array_inc[cur_inc][1];

		if (xi < 0 || xi > n-1 || yi < 0 || yi > n-1 || numbers[xi][yi] != 0) {
			xi = xi - array_inc[cur_inc][0];
			yi = yi - array_inc[cur_inc][1];

			if (cur_inc < 3) {
				cur_inc++;
			} else{
				cur_inc = 0;
			}

			xi = xi + array_inc[cur_inc][0];
			yi = yi + array_inc[cur_inc][1];
		}

		x = xi;
		y = yi;
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			printf("%3d ", numbers[i][j]);
		}
		printf("\n");
	}

}
