#ifndef EMPLOYEE_SEARCH_MANIPULATION_H
#define EMPLOYEE_SEARCH_MANIPULATION_H

#include "../employee/employee.h"
#include "../files/files.h"
#include "../key/key.h"

typedef struct out_file {
    char *name;
    struct out_file *next;
} out_t;

void insertion_sort(key_t *, int);

out_t *populate_out_t(out_t *out, int total);

employee_t *sequential_search(key_t *, int, int);

employee_t *binary_search(key_t *, int, int);

key_t *delete_key(key_t *, int, int);

void internal_classification(const out_t *, int);

#endif //EMPLOYEE_SEARCH_MANIPULATION_H
