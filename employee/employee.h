#ifndef EMPLOYEE_SEARCH_EMPLOYEE_H
#define EMPLOYEE_SEARCH_EMPLOYEE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

typedef struct Employee {
    int id;
    char name[100];
    char document[20];
    char birth_date[20];
    double income;
} TEmployee;

#endif //EMPLOYEE_SEARCH_EMPLOYEE_H
