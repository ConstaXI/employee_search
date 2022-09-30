#ifndef EMPLOYEE_SEARCH_FILES_H
#define EMPLOYEE_SEARCH_FILES_H

#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <stdio.h>

#include "../employee/employee.h"
#include "../key/key.h"
#include "../btree/btree.h"

void *read_data(char *, int, size_t);

TKey* write_employees(char *, TEmployee *, int);

void write_keys(char *, TKey *, int);

void *read_target(char *filename, int target, size_t size_of_type);

#endif //EMPLOYEE_SEARCH_FILES_H
