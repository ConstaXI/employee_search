#include "files/files.h"
#include "employee/employee.h"
#include "interface/interface.h"
#include "generate/generation.h"
#include "btree/btree.h"
#include "hash/hash.h"

int main() {
    employee_t* employees = generate_employees(TOTAL_REGISTERS);

    key_t * keys = generate_keys(employees, TOTAL_REGISTERS);

    write_data("employees.bin", employees, TOTAL_REGISTERS, sizeof(employee_t));

    write_data("employees_keys.bin", keys, TOTAL_REGISTERS, sizeof(key_t));

    create_btree(keys, TOTAL_REGISTERS);

    int hash_table_size = 1000;

    key_t * hash_table = create_hash_table(keys, hash_table_size);

    print_hash_table(hash_table, hash_table_size);

    menu(keys, 0);

    free(employees);
    free(keys);
    free(hash_table);

    return 0;
}
