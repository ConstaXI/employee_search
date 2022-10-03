#ifndef EMPLOYEE_SEARCH_GENERATION_H
#define EMPLOYEE_SEARCH_GENERATION_H

#include <stdio.h>
#include <stdlib.h>

#include "../employee/employee.h"
#include "../files/files.h"
#include "../key/key.h"

TEmployee* generate_employees(int);

TKey *generate_keys(TEmployee *employees, int total);

#endif //EMPLOYEE_SEARCH_GENERATION_H
