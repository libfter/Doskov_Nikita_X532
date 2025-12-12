#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#define SIZE 9
int sudoku1[SIZE][SIZE] = {
    {5, 3, 4, 6, 7, 8, 9, 1, 2},
    {6, 7, 2, 1, 9, 5, 3, 4, 8},
    {1, 9, 8, 3, 4, 2, 5, 6, 7},
    {8, 5, 9, 7, 6, 1, 4, 2, 3},
    {4, 2, 6, 8, 5, 3, 7, 9, 1},
    {7, 1, 3, 9, 2, 4, 8, 5, 6},
    {9, 6, 1, 5, 3, 7, 2, 8, 4},
    {2, 8, 7, 4, 1, 9, 6, 3, 5},
    {3, 4, 5, 2, 8, 6, 1, 7, 9}
};

//a[sudoku1[i]]++;

int sudoku[SIZE][SIZE] = {
    {5,3,7, 6,1,9, 8,2,4},
    {6,8,2, 5,3,4, 7,9,1},
    {1,9,4, 2,7,8, 5,6,3},
    
    {8,2,5, 4,6,7, 1,3,9},
    {4,7,1, 9,8,3, 6,4,2},
    {9,6,3, 1,2,5, 4,7,8},

    {2,1,9, 7,4,6, 3,8,5},
    {7,4,8, 3,5,2, 9,1,6},
    {3,5,6, 8,9,1, 2,4,7}
};

void print_sudoku(int sudoku[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            printf("%d ", sudoku[row][col]);
        }
        printf("\n");
    }
}


int check_rows(int sudoku[9][9]) {
    for (int row = 0; row < 9; row++) {
        int sum = 0;
        for (int col = 0; col < 9; col++) {
            sum += sudoku[row][col];
        }
        if (sum != 45) {
            return row+1;
        }
    }

    return 0;
}

int check_columns(int sudoku[9][9]) {
    for (int col = 0; col < 9; col++) {
        int sum = 0;
        for (int row = 0; row < 9; row++) {
            sum += sudoku[row][col];
        }
        if (sum != 45) {
            return col+1;
        }
    }

    return 0;
}


int check_squares(int sudoku[9][9]) {
    //for rows and cols of squares
    for (int srow = 0; srow < 3; srow++) {
        for (int scol = 0; scol < 3; scol++) {
            int sum = 0;
            //for rows and cols in square
            for (int row = 0 + srow * 3; row < 3 + srow * 3; row++) {
                for (int col = 0 + scol * 3; col < 3 + scol * 3; col++) {
                    sum += sudoku[row][col];
                }
            }

            if (sum != 45) {
                return srow * 3 + scol + 1;
            }
        }
    }

    return 0;
}


bool is_valid_sudoku(int sudoku[9][9]) {
    int cols = check_columns(sudoku);
    int rows = check_rows(sudoku);
    int squares = check_squares(sudoku);

    if (cols + rows + squares == 0) {
        return true;
    } else {
        printf("\n------error------\n");
        printf("%d square\n", squares);
        printf("%d row\n", rows);
        printf("%d column\n", cols);

        return false;
    }
}


int main() {
    print_sudoku(sudoku);

    if (is_valid_sudoku(sudoku)) {
        printf("\nAll correct, sudoku is valid\n");
    }

    return 0;
}