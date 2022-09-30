#include "generation.h"

char *random_name() {
    char *name = (char *) malloc(50 * sizeof(char));
    char *first_name = (char *) malloc(50 * sizeof(char));
    char *last_name = (char *) malloc(50 * sizeof(char));

    int first_name_length = rand() % 10 + 1;
    for (int i = 0; i < first_name_length; i++) {
        first_name[i] = (char) (rand() % 26 + 97);
    }
    first_name[first_name_length] = '\0';

    int last_name_length = rand() % 10 + 1;
    for (int i = 0; i < last_name_length; i++) {
        last_name[i] = (char) (rand() % 26 + 97);
    }
    last_name[last_name_length] = '\0';

    strcpy(name, first_name);
    strcat(name, " ");
    strcat(name, last_name);

    return name;
}

char *random_date() {
    char *date = malloc(sizeof(char) * 11);
    int day, month, year;
    day = rand() % 30 + 1;
    month = rand() % 12 + 1;
    year = rand() % 100 + 1900;
    sprintf(date, "%d/%d/%d", day, month, year);
    return date;
}

char *random_document() {
    char *document = malloc(sizeof(char) * 20);
    int first_part, second_part, third_part, fourth_part;
    first_part = rand() % 100;
    second_part = rand() % 100;
    third_part = rand() % 100;
    fourth_part = rand() % 10;
    sprintf(document, "%d.%d.%d-%d", first_part, second_part, third_part, fourth_part);
    return document;
}

TEmployee* generate_employees(int total) {
    TEmployee *employees = malloc(sizeof(TEmployee) * total);

    for (int i = 0; i < total; i++) {
        const int key = rand() % 100000;
        employees[i].id = key;
        strcpy(employees[i].name, random_name());
        strcpy(employees[i].document, random_document());
        strcpy(employees[i].birth_date, random_date());
        employees[i].income = rand() % 100000;
    }

    return employees;
}
