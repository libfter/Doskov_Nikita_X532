#include "triangle.h"

void add_triangle(struct triangle *arr, int i, int a, int b, int c) {
    arr[i].a = a;
    arr[i].b = b;
    arr[i].c = c;
}

int biggest_square(struct triangle *arr) {
    int biggest_square_id = 0;
    float biggest_square = 0;

    for (int i = 0; i < 3; i++) {
        float square = (arr[i].a * arr[i].b) / 2;

        if (square > biggest_square) {
            biggest_square_id = i;
            biggest_square = square;
        }
    }

    return biggest_square_id;
}