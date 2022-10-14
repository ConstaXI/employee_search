#ifndef EMPLOYEE_SEARCH_FILES_H
#define EMPLOYEE_SEARCH_FILES_H

#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <stdio.h>

extern int TOTAL_REGISTERS;

extern int OUTPUT_FILES_ORDER;

void *read_data(char *, int, size_t);

void* write_data(char *, void *, int, size_t);

void *read_target(char *filename, long target, size_t size_of_type);

void *write_target(char *filename, long target, size_t size_of_type, void *data);

#endif //EMPLOYEE_SEARCH_FILES_H
