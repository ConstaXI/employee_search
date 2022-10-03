#ifndef EMPLOYEE_SEARCH_MANIPULATION_H
#define EMPLOYEE_SEARCH_MANIPULATION_H

#include "../employee/employee.h"
#include "../files/files.h"
#include "../key/key.h"

void insertion_sort(TKey *, int);

TEmployee *sequential_search(TKey *, int, int);

TEmployee *binary_search(TKey *, int, int);

TKey *delete_key(TKey *keys, int total, int id);

#endif //EMPLOYEE_SEARCH_MANIPULATION_H
