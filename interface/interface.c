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

void menu(TKey *data, int total, int is_sorted) {
    int option;
    printf("\nMENU:\n");
    printf("\nSORTING\n");
    printf("1 - Insertion sort\n\n");
    printf("\nSEARCHING\n");
    if (is_sorted) {
        printf("2 - Binary search\n");
    } else {
        printf("2 - Binary search - FILE IS NOT SORTED\n");
    }
    printf("3 - Sequential search\n");
    printf("4 - Find with B Tree\n\n");
    printf("\nPRINTING\n");
    printf("5 - Print Keys\n");
    printf("6 - Print Employee list\n");
    printf("7 - Print ids from B Tree\n\n");
    printf("\nREMOVING\n");
    printf("8 - Remove from B Tree\n\n");
    printf("9 - EXIT\n");
    scanf("%d", &option);
    switch (option) {
        case 1:
            insertion_sort(data, total);

            is_sorted = 1;

            break;
        case 2: {
            if (!is_sorted) {
                printf("\nFILE IS NOT SORTED\n");
                exit(10);
            }

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
            TKey *key = find(get_main_root(), input_code());

            if (key == NULL) {
                printf("\nKey not found\n");
                break;
            }

            TEmployee *employee = read_target("employees.bin", key->id, sizeof(TEmployee));

            print_employee(employee);

            break;
        }
        case 5: {
            print_keys(data, total);

            break;
        }
        case 6: {
            TEmployee *employees = read_data("employees.bin", total, sizeof(TEmployee));

            print_employees(employees, total);

            break;
        }
        case 7: {
            print_btree_keys(get_main_root());

            break;
        }
        case 8: {
            TKey *key = find(get_main_root(), input_code());

            if (key == NULL) {
                printf("\nKey not found\n");
                break;
            }

            delete(key->id);

            data = delete_key(data, total, key->id);

            write_data("employees_keys.bin", data, total - 1, sizeof(TKey));

            TOTAL_REGISTERS--;

            break;
        }
        case 9:
            exit(0);
        default:
            printf("\nInvalid option\n");
            break;
    }

    menu(data, TOTAL_REGISTERS, is_sorted);
}
