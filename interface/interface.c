#include "interface.h"

void print_employee(employee_t *employee) {
    printf("\nCod: %d\n", employee->id);
    printf("Name: %s\n", employee->name);
    printf("Document: %s\n", employee->document);
    printf("Birth date: %s\n", employee->birth_date);
    printf("Income: %.2f\n", employee->income);
}

void print_employees(employee_t *employees, int total) {
    for (int i = 0; i < total; i++) {
        print_employee(&employees[i]);
    }
}

void print_keys(key_t *keys, int total) {
    for (int i = 0; i < total; i++) {
        printf("%d -> %d", keys[i].id, keys[i].position);
        printf("\n");
    }
}

int input_code() {
    int id;
    printf("\nEnter the code: ");
    scanf("%d", &id);
    return id;
}

void menu(key_t *data, int is_sorted) {
    int option;
    printf("\nMENU:\n");
    printf("\nINSERTING\n");
    printf("-1 - Insert in BTree\n");
    printf("\nSORTING\n");
    printf("0 - Generate sorted partitions\n");
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
    printf("5 - Print Keys from key's file\n");
    printf("6 - Print employees from employee's file\n");
    printf("7 - Print ids from B Tree\n\n");
    printf("\nREMOVING\n");
    printf("8 - Remove from B Tree\n\n");
    printf("\nHASH TABLE\n");
    printf("9 - Create Hash Table\n");
    printf("10 - Create Chained Hash Table\n");
    printf("\n99 - EXIT\n");
    scanf("%d", &option);
    switch (option) {
        case -1: {
            employee_t *employee = generate_employee();

            int free_pos = find_free_position(data, TOTAL_REGISTERS);

            key_t *key = generate_key(employee->id, free_pos);

            insert(get_main_root(), key);

            write_target("employees.bin", free_pos, sizeof(employee_t), employee);

            write_target("employees_keys.bin", TOTAL_REGISTERS, sizeof(key_t), key);

            printf("inserted in position %d:\n", free_pos);

            print_employee(employee);

            TOTAL_REGISTERS++;

            break;
        }
        case 0: {
            out_t *files = malloc(sizeof(out_t) * OUTPUT_FILES_ORDER);

            populate_out_t(files, OUTPUT_FILES_ORDER);

            internal_classification(files, OUTPUT_FILES_ORDER);

            free(files);

            break;
        }
        case 1:
            insertion_sort(data, TOTAL_REGISTERS);

            is_sorted = 1;

            break;
        case 2: {
            if (!is_sorted) {
                printf("\nFILE IS NOT SORTED\n");
                exit(10);
            }

            int cod = input_code();

            employee_t *employee = binary_search(data, TOTAL_REGISTERS, cod);

            print_employee(employee);

            break;
        }
        case 3: {
            employee_t *employee = sequential_search(data, TOTAL_REGISTERS, input_code());

            print_employee(employee);

            break;
        }
        case 4: {
            key_t *key = find(get_main_root(), input_code());

            if (key == NULL) {
                printf("\nKey not found\n");
                break;
            }

            employee_t *employee = read_target("employees.bin", key->position, sizeof(employee_t));

            print_employee(employee);

            break;
        }
        case 5: {
            key_t *keys = read_data("employees_keys.bin", TOTAL_REGISTERS, sizeof(key_t));

            print_keys(keys, TOTAL_REGISTERS);

            free(keys);

            break;
        }
        case 6: {
            employee_t *employees = read_data("employees.bin", TOTAL_REGISTERS, sizeof(employee_t));

            print_employees(employees, TOTAL_REGISTERS);

            free(employees);

            break;
        }
        case 7: {
            print_btree_keys(get_main_root());

            break;
        }
        case 8: {
            key_t *key = find(get_main_root(), input_code());

            if (key == NULL) {
                printf("\nKey not found\n");
                break;
            }

            delete(key->id);

            key_t * keys = read_data("employees_keys.bin", TOTAL_REGISTERS, sizeof(key_t));

            delete_key(keys, TOTAL_REGISTERS, key->id);

            TOTAL_REGISTERS--;

            write_data("employees_keys.bin", keys, TOTAL_REGISTERS, sizeof(key_t));

            break;
        }
        case 9 : {
            int hash_table_size = 1000;

            key_t * hash_table = create_hash_table(data, hash_table_size);

            print_hash_table(hash_table, hash_table_size);

            free(hash_table);

            break;
        }
        case 10: {
            chain_hash_t * chained_hash_table = create_chained_hash_table(data, 100);

            print_chained_hash_table(chained_hash_table, 100);

            free(chained_hash_table);

            break;
        }
        case 99:
            exit(0);
        default:
            printf("\nInvalid option\n");
            break;
    }

    menu(read_data("employees_keys.bin", TOTAL_REGISTERS, sizeof(key_t)), is_sorted);
}
