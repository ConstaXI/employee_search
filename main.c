#include "files/files.h"
#include "employee/employee.h"
#include "interface/interface.h"
#include "generate/generation.h"
#include "btree/btree.h"

int main() {
    employee_t* employees = generate_employees(TOTAL_REGISTERS);

    TKey * keys = generate_keys(employees, TOTAL_REGISTERS);

    write_data("employees.bin", employees, TOTAL_REGISTERS, sizeof(employee_t));

    write_data("employees_keys.bin", keys, TOTAL_REGISTERS, sizeof(TKey));

    create_btree(keys, TOTAL_REGISTERS);

    menu(keys, TOTAL_REGISTERS, 0);

    free(employees);
    free(keys);

    return 0;
}
