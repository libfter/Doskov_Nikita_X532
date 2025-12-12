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


void print_answers(int size, double *answers) {
    printf("\nОтвет: ");
    for (int row = 0; row < size; row++) {
        printf("x%d = %.2lf ", row, answers[row]);
    }
    printf("\n");
}


int input_size() {
    int size = -1;

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


double *input_b(int size) {
    double *b = (double *)malloc(size * sizeof(double));

    for (int row = 0; row < size; row++) {
        printf("b[%d] >>> ", row);
        scanf("%lf", &b[row]);
    }

    return b;
}


double *solve_matrix(int size, double **matrix, double b[size]) {
    //declaration temp_matrix
    double **temp_matrix = (double **)malloc(size * sizeof(double *));
    for (int row = 0; row < size; row++) {
        temp_matrix[row] = (double *)malloc(size * sizeof(double));
    }

    double *answers = (double*)malloc(size * sizeof(double));
    double det_a = determinant(size, matrix);

    if (det_a == 0) {
        printf("no only solve\n");
    } else {
        //for each column
        for (int j = 0; j < size; j++) {
            //copy matrix to temp_matrix
            for (int row = 0; row < size; row++) {
                for (int col = 0; col < size; col++) {
                    temp_matrix[row][col] = matrix[row][col];
                }
            }

            //replace j collumn to B
            for (int row = 0; row < size; row++) {
                temp_matrix[row][j] = b[row];
            }

            //determinant Aj
            double det_aj = determinant(size, temp_matrix);

            //print solve x[j]
            answers[j] = det_aj / det_a;
        }
    }
    
    return answers;
}


int main() {
    int n = input_size();

    double** matrix = input_matrix(n);

    double *b = input_b(n);

    double *answers = solve_matrix(n, matrix, b);

    print_answers(n, answers);

    return 0;
}