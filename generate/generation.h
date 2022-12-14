#ifndef EMPLOYEE_SEARCH_GENERATION_H
#define EMPLOYEE_SEARCH_GENERATION_H

#include <stdio.h>
#include <stdlib.h>

#include "../employee/employee.h"
#include "../files/files.h"
#include "../key/key.h"

employee_t* generate_employees(int);

key_t *generate_keys(employee_t *employees, int total);

employee_t* generate_employee();

#endif //EMPLOYEE_SEARCH_GENERATION_H
