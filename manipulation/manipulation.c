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

employee_t *sequential_search(TKey *data, int total, int cod) {
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

    employee_t *employee = read_target("employees.bin", position_target, sizeof(employee_t));

    clock_t end = clock();

    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("\nsequential_search execution time: %lf seconds\ncomparisons: %d\n", time_spent, comparisons);

    return employee;
}

employee_t *binary_search(TKey *data, int total, int cod) {
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

employee_t *read_employee(FILE *file) {
    employee_t *employee = (employee_t *) malloc(sizeof(employee_t));
    fread(&employee->id, sizeof(int), 1, file);
    fread(&employee->name, sizeof(char), 100, file);
    fread(&employee->document, sizeof(int), 20, file);
    fread(&employee->birth_date, sizeof(char), 20, file);
    fread(&employee->income, sizeof(float), 1, file);
    return employee;
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

void internal_classification(char *in_file, const out_t *out_file, int size) {
    int end = 0;
    FILE *file;
    if ((file = fopen(in_file, "rb")) == NULL) {
        exit(1);
    } else {
        employee_t *employee = read_employee(file);
        while (!(end)) {
            employee_t *v[size];
            int i = 0;
            while (!feof(file) && i < size) {
                v[i] = employee;
                employee = read_employee(file);
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
            if (feof(file)) {
                end = 1;
            }
        }
    }
}
