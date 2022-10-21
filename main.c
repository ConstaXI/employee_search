#include "files/files.h"
#include "employee/employee.h"
#include "interface/interface.h"
#include "generate/generation.h"
#include "btree/btree.h"

int main() {
    employee_t* employees = generate_employees(TOTAL_REGISTERS);

    key_t * keys = generate_keys(employees, TOTAL_REGISTERS);

    write_data("employees.bin", employees, TOTAL_REGISTERS, sizeof(employee_t));

    write_data("employees_keys.bin", keys, TOTAL_REGISTERS, sizeof(key_t));

    create_btree(keys, TOTAL_REGISTERS);

    menu(keys, 0);

    free(employees);
    free(keys);

    return 0;
}
