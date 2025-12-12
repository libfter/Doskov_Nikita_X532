#include <stdio.h>


void print_matrix(int size, double a[size][size]/*double b[size]*/) {
    printf("\n");
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            printf("%.3f ", a[i][j]);
        }
        //printf(" | %.3lf", b[i]);
        printf("\n");
    }
    printf("\n");
}


void remove_col_row(int size, double a[size][size], double minor[size-1][size-1], int row, int col) {
    int mrow = 0;
    for (int i=0; i<size-1; i++) {
        
        if (i==row) {
            continue;
        }

        int mcol = 0;
        for (int j=0; j<size-1; j++) {
            
            if (j==col) {
                continue;
            }
            
            minor[row][col] = a[i][j];
            mcol++;
        }
        mrow++;
    }
    
    print_matrix(size-1, minor);
}


double determinant(int size, double a[size][size]) {
    switch (size) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return a[0][0] * a[1][1] - a[0][1] * a[1][0];
    default:
        double det = 0.0;
        int sign = -1;
        
        for (int j=0; j<size; j++) {
            double minor[size-1][size-1];
            remove_col_row(size, a, minor, 0, j);

            det += sign * a[0][j] * determinant(size-1, minor);
            sign *= -1;
        }

        return det;
    }
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


int input_size() {
    int n = -1;
    while (n < 0) {
        printf("n >>> ");
        scanf("%d", &n);

        if (n <= -1) {
            printf("n < 0!\n");
        }
    }
    return n;
}


int main() {
    int n = input_size();

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

    //print_matrix(n, a);
    printf("det(A) = %.3lf\n\n", determinant(n, a));
    //solve_matrix(n, a, b);

    return 0;
}