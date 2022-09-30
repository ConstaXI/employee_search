#ifndef EMPLOYEE_SEARCH_EMPLOYEE_H
#define EMPLOYEE_SEARCH_EMPLOYEE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

typedef struct Employee {
    int cod;
    char name[100];
    char document[12];
    char birth_date[20];
    double income;
} TEmployee;

typedef struct Key {
    int cod;
    int key;
} TKey;

#endif //EMPLOYEE_SEARCH_EMPLOYEE_H
