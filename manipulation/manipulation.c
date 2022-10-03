#include "manipulation.h"

void insertion_sort(TKey *data, int total) {
    clock_t begin = clock();

    int i, j;

    TKey aux;

    for (i = 1; i < total; i++) {
        aux = data[i];
        j = i - 1;
        while (j >= 0 && data[j].id > aux.id) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = aux;
    }

    write_data("employees_keys.bin", data, total, sizeof(TKey));

    clock_t end = clock();

    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("\ninsertion_sort execution time: %lf seconds\n", time_spent);
}

TKey * delete_key(TKey *data, int total, int id) {
    int i;

    for (i = 0; i < total; i++) {
        if (data[i].id == id) {
            break;
        }
    }

    for (i; i < total - 1; i++) {
        data[i] = data[i + 1];
    }

    return data;
}

TEmployee *sequential_search(TKey *data, int total, int cod) {
    clock_t begin = clock();
    int i;

    int position_target = 0;
    int comparisons = 0;

    for (i = 0; i < total; i++) {
        comparisons++;
        if (data[i].id == cod) {
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
        if (data[m].id == cod) {
            position_target = data[m].key;
            break;
        } else if (data[m].id > cod)
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
