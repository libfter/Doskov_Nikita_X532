#include <stdio.h>

#define N 6


void print_comlex(int *array) {
    for (int i = 0; i < N; i+=2) {
        printf("s[%d] = %d + j*(%d)\n", i, array[i], array[i+1]);
    }
}


void calc_energy(int *array) {
    long long int energy;
    for (int i = 0; i < N; i+=2) {
        energy += array[i]*array[i] + array[i+1]*array[i+1];
    }
    printf("energy = %lld\n", energy);
}


void print_max(int *array) {
    int max = 0;
    for (int i = 0; i < N; i+=2) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    printf("max = %d\n", max);
}


int main() {
    int complex[N] = {3748, 30432, 1225, 2045, 1822, 6472};

    print_comlex(complex);
    calc_energy(complex);
    print_max(complex);

    return 0;
}