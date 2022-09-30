#include "interface.h"

void print_employee(TEmployee *employee) {
    printf("\nCod: %d\n", employee->cod);
    printf("Name: %s\n", employee->name);
    printf("Document: %s\n", employee->document);
    printf("Birth date: %s\n", employee->birth_date);
    printf("Income: %.2f\n", employee->income);
}

void print_employees(TEmployee *employees, int total) {
    for (int i = 0; i < total; i++) {
        print_employee(&employees[i]);
    }
}

void print_keys(TKey *keys, int total) {
    for (int i = 0; i < total; i++) {
        printf("%d -> %d", keys[i].cod, keys[i].key);
        printf("\n");
    }
}

int input_code() {
    int cod;
    printf("\nEnter the code: ");
    scanf("%d", &cod);
    return cod;
}

void select_sorting_method(TKey *data, int total) {
    int option;
    printf("\nMENU:\n");
    printf("1 - Insertion sort\n");
    printf("2 - Binary search\n");
    printf("3 - Sequential search\n");
    printf("4 - Print Employee list\n");
    printf("5 - Print Employees Keys\n");
    printf("9 - Exit\n");
    scanf("%d", &option);
    switch (option) {
        case 1:
            insertion_sort(data, total);
            select_sorting_method(data, total);
            break;
        case 2: {
            printf("Remember to sort the employees first.\n");

            int cod = input_code();

            TEmployee *employee = binary_search(data, total, cod);

            print_employee(employee);

            select_sorting_method(data, total);

            break;
        }
        case 3: {
            int cod = input_code();

            TEmployee *employee = sequential_search(data, total, cod);

            print_employee(employee);

            free(employee);

            select_sorting_method(data, total);

            break;
        }
        case 4: {
            TEmployee *employees = read_data("employees.bin", total, sizeof(TEmployee));

            print_employees(employees, total);

            select_sorting_method(data, total);

            break;
        }
        case 5: {
            TKey *keys = read_data("employees_keys.bin", total, sizeof(TKey));

            print_keys(keys, total);

            select_sorting_method(data, total);
            break;
        }
        case 9:
            exit(0);
        default:
            printf("\nInvalid option\n");
            select_sorting_method(data, total);
            break;
    }
}
