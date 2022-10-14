#ifndef EMPLOYEE_SEARCH_INTERFACE_H
#define EMPLOYEE_SEARCH_INTERFACE_H

#include <conio.h>
#include "../employee/employee.h"
#include "../manipulation/manipulation.h"
#include "../generate/generation.h"
#include "../key/key.h"
#include "../btree/btree.h"
#include "../files/files.h"

void print_employee(employee_t *);

int input_code();

void menu(key_t *, int);

void print_keys(key_t *, int);

#endif //EMPLOYEE_SEARCH_INTERFACE_H
