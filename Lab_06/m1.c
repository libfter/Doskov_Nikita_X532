#include <stdio.h>
#include <stdlib.h>


double determinant(int size, double **matrix) {
    switch (size) {
    case 0:
        return 0.0;
    case 1:
        return matrix[0][0];
    case 2:
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    case 3:
        return matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0] + matrix[1][0] * matrix[2][1] * matrix[0][2] - matrix[0][2] * matrix[1][1] * matrix[2][0] - matrix[1][0] * matrix[0][1] * matrix[2][2] - matrix[2][1] * matrix[1][2] * matrix[0][0];
    }
}


void print_matrix(int size, double **matrix) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
}


int input_size() {
    int size = 0;

    while (size < 1 || 3 < size) {
        printf("n (>0) >>> ");
        scanf("%d", &size);
    }

    return size;
}


double **input_matrix(int size) {
    double **matrix = (double **)malloc(size * sizeof(double*));

    for (int i = 0; i < size; i++) {
        matrix[i] = (double *)malloc(size * sizeof(double));
        for (int j = 0; j < size; j++) {
            printf("matrix[%d][%d] >>> ", i, j);
            scanf("%lf", &matrix[i][j]);
        }
    }

    return matrix;
}


int main() {
    int n = input_size();
    double** matrix = input_matrix(n);
    print_matrix(n, matrix);
    printf("%.3lf\n", determinant(n, matrix));

    return 0;
}