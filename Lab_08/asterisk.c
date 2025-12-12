#include <stdio.h>
#include <stdlib.h>

int time = 1;

int **init_cache(int size) {
    int **res = malloc(2 * sizeof(int*));

    int *cache = calloc(size, size * sizeof(int));
    res[0] = cache;
    int *usage = calloc(size, size * sizeof(int));
    res[1] = usage;

    return res;
}


void get_value(int *cache, int *usage, int size, int value) {
    int first_usage = __INT_MAX__;
    int first_usage_id = 0;

    for (int i = 0; i < size; i++) {
        
        if (first_usage > usage[i]) {
            first_usage = usage[i];
            first_usage_id = i;
        }

        if (cache[i] == value) { //value in cache
            printf("НАЙДЕНО в кэше (обновляем время использования)");
            usage[i] = time;
            return;
        } else if (cache[i] == 0) { //value not in cache + empty cell
            printf("НЕ найдено, добавляем в кэш");
            cache[i] = value;
            usage[i] = time;
            return;
        }
    }
    //value not in cache + all cache busy
    printf("НЕ найдено, заменяем элемент с самым старым временем использования");
    cache[first_usage_id] = value;
    usage[first_usage_id] = time;
}


void print_cache(int *cache, int *usage, int size) {
    printf("\nКэш: [");
    for (int i = 0; i < size; i++) {
        printf(" %d(%d) ", cache[i], usage[i]);
    }
    printf("]\n");
}


void free_cache(int *cache, int *usage) {
    free(cache);
    cache = NULL;
    free(usage);
    usage = NULL;
}


int main() {
    int size = 0;
    printf("size >>> ");
    scanf("%d", &size);

    int **a = init_cache(size);
    int *cache = a[0];
    int *usage = a[1];

    while (1) {
        int value;
        printf("Запрос: ");
        scanf("%d", &value);
        get_value(cache, usage, size, value);
        print_cache(cache, usage, size);
        time++;
    }

    free_cache(cache, usage);

    return 0;
}