//Вариант 6
#include <stdio.h>
#include <stdlib.h>
#include "triangle.h"


int main() {
    struct triangle *triangles = NULL; 
    triangles = (struct triangle *)malloc(3 * sizeof(struct triangle));
    
    add_triangle(triangles, 0, 1, 2, 4);
    add_triangle(triangles, 1, 2, 3, 6);
    add_triangle(triangles, 2, 3, 4, 8);

    printf("Треугольник с большей площадью - %d\n", biggest_square(triangles));
}