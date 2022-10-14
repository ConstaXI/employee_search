#include "manipulation.h"

void insertion_sort(key_t *data, int total) {
    clock_t begin = clock();

    int i, j;

    key_t aux;

    for (i = 1; i < total; i++) {
        aux = data[i];
        j = i - 1;
        while (j >= 0 && data[j].id > aux.id) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = aux;
    }

    write_data("employees_keys.bin", data, total, sizeof(key_t));

    clock_t end = clock();

    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("\ninsertion_sort execution time: %lf seconds\n", time_spent);
}

key_t * delete_key(key_t *data, int total, int id) {
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

employee_t *sequential_search(key_t *data, int total, int cod) {
    clock_t begin = clock();
    int i;

    int position_target = 0;
    int comparisons = 0;

    for (i = 0; i < total; i++) {
        comparisons++;
        if (data[i].id == cod) {
            position_target = data[i].position;
            break;
        }
    }

    employee_t *employee = read_target("employees.bin", position_target, sizeof(employee_t));

    clock_t end = clock();

    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("\nsequential_search execution time: %lf seconds\ncomparisons: %d\n", time_spent, comparisons);

    return employee;
}

employee_t *binary_search(key_t *data, int total, int cod) {
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
            position_target = data[m].position;
            break;
        } else if (data[m].id > cod)
            j = m - 1;
        else
            i = m + 1;
    }

    employee_t *employee = read_target("employees.bin", position_target, sizeof(employee_t));

    clock_t end = clock();

    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("\nbinary_search_return execution time: %lf, \ncomparisons: %d\n", time_spent, comparisons);

    return employee;
}

void save_employee(employee_t *employee, FILE *file) {
    fwrite(&employee->id, sizeof(int), 1, file);
    fwrite(&employee->name, sizeof(char), 100, file);
    fwrite(&employee->document, sizeof(int), 20, file);
    fwrite(&employee->birth_date, sizeof(char), 20, file);
    fwrite(&employee->income, sizeof(float), 1, file);
}

out_t *populate_out_t(out_t *out, int total) {
    int i;
    for (i = 0; i < total; i++) {
        out[i].name = malloc(sizeof(char) * 100);
        sprintf(out[i].name, "employee_partition_%d.bin", i);
        out[i].next = &out[i + 1];
    }
    out[total - 1].next = NULL;
    return out;
}

void internal_classification(const out_t *out_file, int size) {
    while (out_file != NULL) {
        employee_t *v[size];
        int i = 0;
        while (i < size) {
            v[i] = read_target("employees.bin", i, sizeof(employee_t));
            i++;
        }
        if (i != size) {
            size = i;
        }
        for (int j = 1; j < size; j++) {
            employee_t *c = v[j];
            i = j - 1;
            while ((i >= 0) && (v[i]->id > c->id)) {
                v[i + 1] = v[i];
                i = i - 1;
            }
            v[i + 1] = c;
        }
        char *partition = out_file->name;
        out_file = out_file->next;
        FILE *p;
        if ((p = fopen(partition, "wb")) == NULL) {
            exit(1);
        } else {
            for (int j = 0; j < size; j++) {
                save_employee(v[j], p);
            }
            fclose(p);
        }
    }
}
