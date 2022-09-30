#include "interface.h"

void print_employee(TEmployee *employee) {
    printf("\nCod: %d\n", employee->id);
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
        printf("%d -> %d", keys[i].id, keys[i].key);
        printf("\n");
    }
}

int input_code() {
    int id;
    printf("\nEnter the code: ");
    scanf("%d", &id);
    return id;
}

void btree_menu(TKey *keys, int total) {
    int option = 0;
    int id;

    while (option != 3) {
        printf("\n1 - Search by code\n2 - Print keys\n3 - Exit\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                id = input_code();
                TKey *key = find(get_main_root(), id);
                TEmployee *employee = read_target("employees.bin", key->id, sizeof(TEmployee));
                print_employee(employee);
                break;
            case 2:
                print_keys(keys, total);
                break;
            case 3:
                break;
            default:
                printf("\nInvalid option\n");
                btree_menu(keys, total);
                break;
        }
    }
}

void menu(TKey *data, int total) {
    int option;
    printf("\nMENU:\n");
    printf("1 - Insertion sort\n");
    printf("2 - Binary search\n");
    printf("3 - Sequential search\n");
    printf("4 - Print Employee list\n");
    printf("5 - Print Employees Keys\n");
    printf("6 - Find with B Tree\n");
    printf("7 - Remove from B Tree\n");
    printf("8 - Print ids from B Tree\n");
    printf("9 - Exit\n");
    scanf("%d", &option);
    switch (option) {
        case 1:
            insertion_sort(data, total);

            break;
        case 2: {
            printf("Remember to sort the employees first.\n");

            int cod = input_code();

            TEmployee *employee = binary_search(data, total, cod);

            print_employee(employee);

            break;
        }
        case 3: {
            TEmployee *employee = sequential_search(data, total, input_code());

            print_employee(employee);

            break;
        }
        case 4: {
            TEmployee *employees = read_data("employees.bin", total, sizeof(TEmployee));

            print_employees(employees, total);

            break;
        }
        case 5: {
            TKey *keys = read_data("employees_keys.bin", total, sizeof(TKey));

            print_keys(keys, total);

            break;
        }
        case 6: {
            TKey *key = find(get_main_root(), input_code());

            if (key == NULL) {
                printf("\nKey not found\n");
                break;
            }

            TEmployee *employee = read_target("employees.bin", key->id, sizeof(TEmployee));

            print_employee(employee);

            break;
        }
        case 7: {
            delete(input_code());

            break;
        }
        case 8: {
            print_btree_keys(get_main_root());

            break;
        }
        case 9:
            exit(0);
        default:
            printf("\nInvalid option\n");
            break;
    }

    menu(data, total);
}
