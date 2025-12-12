/*
7. Получить матрицу D[m,n] путем умножения матрицы B[m,k] на
матрицу E[k,n]. Определить в результирующей матрице столбец с
наибольшей суммой отрицательных элементов. Упорядочить этот
столбец по убыванию.
*/
#include <stdio.h>
#include <stdlib.h>


double **input_matrix(int width, int height) {
    double **matrix = malloc(height * sizeof(double *));

    for (int row = 0; row < height; row++) {
        matrix[row] = malloc(width * sizeof(double));
        for (int col = 0; col < width; col++) {
            printf("matrix[%d][%d] >>> ", row, col);
            scanf("%lf", &matrix[row][col]);
        }
    }
    printf("\n");

    return matrix;
}


void print_matrix(double **matrix, int width, int height) {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            printf("%.2lf\t", matrix[row][col]);
        }
        printf("\n");
    }
}

/*
B m k
E k n

D m n
*/

double **mlt_matrix(double **matrix1, int width1, int height1, double **matrix2, int width2, int height2) {
    double **matrix3 = malloc(height2 * sizeof(double *));

    for (int row2 = 0; row2 < height2; row2++) {
        matrix3[row2] = (double *)malloc(width1 * sizeof(double));
        for (int col1 = 0; col1 < width1; col1++) {
            double sum = 0;
            
            for (int i = 0; i < height1; i++) {
                sum += matrix1[i][col1] * matrix2[row2][i];
                //printf("%.0lf * %.0lf += %.0lf\n", matrix1[i][col1], matrix2[row2][i], sum);
            }
            //printf("\n");
            matrix3[row2][col1] = sum;
        }
    }

    return matrix3;
}


int get_col_max_sum_of_neg(double **matrix, int width, int height) {
    int col = 0;
    int max_col = -1;
    //*(*(matrix + 1)+0) == matrix[1][0]
    double max_sum = -__DBL_MAX__;

    for (col; col < width; col++) {
        double sum = 0;
        for (int row = 0; row < height; row++) {
            if (matrix[row][col] < 0) {
                sum += matrix[row][col];
            }
        }
        if (sum != 0 && max_sum < sum) {
            max_sum = sum;
            max_col = col;
        }
    }

    return max_col;
}


void sort_col(double **matrix, int height, int col) {
    for (int i = 0; i < height - 1; i++) {
        for (int row = 0; row < height - 1; row++) {
            if (matrix[row][col] < matrix[row + 1][col]) {
                double tmp = matrix[row][col];
                matrix[row][col] = matrix[row + 1][col];
                matrix[row + 1][col] = tmp;
            }
        }
    }
}


void free_matrix(double **matrix, int height) {
    for (int i = 0; i < height; i++) {
        free(matrix[i]);
        matrix[i] = NULL;
    }

    free(matrix);
    matrix = NULL;
}


int main() {
    printf("B[m,k] * E[k,n] = D[m,n]\n");

    int m, k, n;
    printf("m = ");
    scanf("%d", &m);
    printf("k = ");
    scanf("%d", &k);
    printf("n = ");
    scanf("%d", &n);

    double **B = input_matrix(m, k);
    double **E = input_matrix(k, n);
    double **D = mlt_matrix(B, m, k, E, k, n);

    printf("\n");
    print_matrix(B, m, k);
    printf("*\n");
    print_matrix(E, k, n);
    printf("=\n");
    print_matrix(D, m, n);

    int c = get_col_max_sum_of_neg(D, m, n);
    if (c != -1) {
        printf("\nСортировка %d столбца:\n", c);
        sort_col(D, n, c);
        print_matrix(D, m, n);
    } else {
        printf("\nотрицательных элементов нет\n");
    }
    
    free_matrix(B, k);
    free_matrix(E, n);
    free_matrix(D, n);

    return 0;
}