//ЗАДАНИЕ 7//
#include <stdio.h>
#include <stdlib.h>


int id_of_min(int *array, int size) {
    int min = 10000000;
    int id = 0;
    
    for (int i = 0; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
            id = i;
        }
    }

    return id;
}


int id_of_max(int *array, int size) {
    int max = -10000000;
    int id = 0;
    
    for (int i = 0; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
            id = i;
        }
    }

    return id;
}


float avarage(int *array, int from, int to) {
    float sum = 0;

    if (from < to) {
        for (int i = from; i < to+1; i++) {
            sum += array[i];
        }
    } else {
        for (int i = from; i > to-1; i--) {
            sum += array[i];
        }
    }

    return sum / (abs(to - from) + 1);
}


int main() {
    int N = 0;
    printf("N >>> ");
    scanf("%d", &N);

    int a[N];
    for (int i = 0; i < N; i++) {
        int num;
        printf("a[%d] >>> ", i);
        scanf("%d", &num);
        a[i] = num;
    }

    int min_id = id_of_min(a, N);
    int max_id = id_of_max(a, N);

    float avg = avarage(a, min_id, max_id);

    printf("min - %d\nmax - %d\navg[min; max] - %.2f\n", a[min_id], a[max_id], avg);

    return 0;
}