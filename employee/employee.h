#ifndef EMPLOYEE_SEARCH_EMPLOYEE_H
#define EMPLOYEE_SEARCH_EMPLOYEE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

typedef struct employee {
    int id;
    char name[100];
    char document[20];
    char birth_date[20];
    double income;
} employee_t;

#endif //EMPLOYEE_SEARCH_EMPLOYEE_H
