#ifndef EMPLOYEE_SEARCH_GENERATION_H
#define EMPLOYEE_SEARCH_GENERATION_H

#include <stdio.h>
#include <stdlib.h>

#include "../employee/employee.h"
#include "../files/files.h"

char *random_date();

char *random_name();

TEmployee* generate_employees(int);

#endif //EMPLOYEE_SEARCH_GENERATION_H
