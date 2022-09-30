#include "files/files.h"
#include "employee/employee.h"
#include "interface/interface.h"
#include "generate/generation.h"
#include "btree/btree.h"

int main() {
    int total = 100;

    TEmployee* employees = generate_employees(total);

    TKey * keys = write_employees("employees.bin", employees, total);

    menu(keys, total);

    free(employees);
    free(keys);

    return 0;
}
