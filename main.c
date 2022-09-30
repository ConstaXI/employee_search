#include "files/files.h"
#include "employee/employee.h"
#include "interface/interface.h"
#include "generate/generation.h"

int main() {
    TEmployee* employees = generate_employees(100);

    TKey * keys = write_employees("employees.bin", employees, 100);

    select_sorting_method(keys, 100);

    free(employees);

    return 0;
}
