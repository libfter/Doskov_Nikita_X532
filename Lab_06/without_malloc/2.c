#include <stdio.h>


double determinant(int size, double a[size][size]) {
    switch (size) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return a[0][0] * a[1][1] - a[0][1] * a[1][0];
    case 3:
        return a[0][0] * a[1][1] * a[2][2] + a[0][1] * a[1][2] * a[2][0] + a[1][0] * a[2][1] * a[0][2] - a[0][2] * a[1][1] * a[2][0] - a[1][0] * a[0][1] * a[2][2] - a[2][1] * a[1][2] * a[0][0];
    default:
        return 37707;
        //minor recursion
    }
}


void print_matrix(int size, double a[size][size], double b[size]) {
    printf("\n");
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            printf("%.3f ", a[i][j]);
        }
        printf(" | %.3lf", b[i]);
        printf("\n");
    }
    printf("\n");
}


void solve_matrix(int size, double a[size][size], double b[size]) {
    double temp_matrix[size][size];
    double x[size];
    double det_a = determinant(size, a);

    printf("solve A|B:\n");

    if (det_a == 0) {
        printf("no only solve\n");
        return;
    }
    
    for (int j=0; j<size; j++) {
        //copy matrix to temp_matrix
        for (int row=0; row<size; row++) {
            for (int col=0; col<size; col++) {
                temp_matrix[row][col] = a[row][col];
            }
        }

        //replace j collumn to B
        for (int row=0; row<size; row++) {
            temp_matrix[row][j] = b[row];
        }

        //determinant Aj
        double det_aj = determinant(size, temp_matrix);

        //print solve x[j]
        x[j] = det_aj / det_a;
        printf("x%d = %.3lf\n", j+1, x[j]);
    }
    printf("\n");
}


int main() {
    int n;
    printf("n >>> ");
    scanf("%d", &n);

    double a[n][n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("a[%d][%d] >>> ", i, j);
            scanf("%lf", &a[i][j]);
        }
    }

    double b[n];
    for (int i=0; i<n; i++) {
        printf("b[%d][%d] >>> ", i, i+n);
        scanf("%lf", &b[i]);
    }

    print_matrix(n, a, b);
    printf("det(A) = %.3lf\n\n", determinant(n, a));
    solve_matrix(n, a, b);

    return 0;
}