#ifndef EMPLOYEE_SEARCH_MANIPULATION_H
#define EMPLOYEE_SEARCH_MANIPULATION_H

#include "../employee/employee.h"
#include "../files/files.h"
#include "../key/key.h"

typedef struct out_file {
    char *name;
    struct out_file *next;
} out_t;

void insertion_sort(TKey *, int);

out_t *populate_out_t(out_t *out, int total);

employee_t *sequential_search(TKey *, int, int);

employee_t *binary_search(TKey *, int, int);

TKey *delete_key(TKey *, int, int);

void internal_classification(const out_t *, int);

#endif //EMPLOYEE_SEARCH_MANIPULATION_H
