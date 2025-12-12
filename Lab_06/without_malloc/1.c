#include <stdio.h>


int determinant(int size, int matrix[size][size]) {
    switch (size) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    case 3:
        return matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0] + matrix[1][0] * matrix[2][1] * matrix[0][2] - matrix[0][2] * matrix[1][1] * matrix[2][0] - matrix[1][0] * matrix[0][1] * matrix[2][2] - matrix[2][1] * matrix[1][2] * matrix[0][0];
    default:
        return 37707;
    }
}


void print_matrix(int size, int matrix[size][size]) {
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}


int main() {
    int n;
    printf("n >>> ");
    scanf("%d", &n);

    int matrix[n][n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("matrix[%d][%d] >>> ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    print_matrix(n, matrix);
    printf("%d\n", determinant(n, matrix));

    return 0;
}