#ifndef EMPLOYEE_SEARCH_INTERFACE_H
#define EMPLOYEE_SEARCH_INTERFACE_H

#include "../employee/employee.h"
#include "../manipulation/manipulation.h"

void print_employee(TEmployee *);

int input_code();

void select_sorting_method(TKey *, int);

void print_keys(TKey *, int);

#endif //EMPLOYEE_SEARCH_INTERFACE_H
