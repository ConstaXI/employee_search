#include "manipulation.h"

void insertion_sort(TKey *data, int total) {
    clock_t begin = clock();

    int i, j;

    TKey aux;

    for (i = 1; i < total; i++) {
        aux = data[i];
        j = i - 1;
        while (j >= 0 && data[j].cod > aux.cod) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = aux;
    }

    write_keys("employees_keys.bin", data, total);

    clock_t end = clock();

    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("\ninsertion_sort execution time: %lf seconds\n", time_spent);
}

TEmployee *sequential_search(TKey *data, int total, int cod) {
    clock_t begin = clock();
    int i;

    int position_target = 0;
    int comparisons = 0;

    for (i = 0; i < total; i++) {
        comparisons++;
        if (data[i].cod == cod) {
            position_target = data[i].key;
            break;
        }
    }

    TEmployee *employee = read_target("employees.bin", position_target, sizeof(TEmployee));

    clock_t end = clock();

    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("\nsequential_search execution time: %lf seconds\ncomparisons: %d\n", time_spent, comparisons);

    return employee;
}

TEmployee *binary_search(TKey *data, int total, int cod) {
    clock_t begin = clock();

    int i, j, m;
    int position_target = 0;
    int comparisons = 0;

    i = 0;
    j = total - 1;

    while (i <= j) {
        comparisons++;
        m = (i + j) / 2;
        if (data[m].cod == cod) {
            position_target = data[m].key;
            break;
        } else if (data[m].cod > cod)
            j = m - 1;
        else
            i = m + 1;
    }

    TEmployee *employee = read_target("employees.bin", position_target, sizeof(TEmployee));

    clock_t end = clock();

    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("\nbinary_search_return execution time: %lf, \ncomparisons: %d\n", time_spent, comparisons);

    return employee;
}
