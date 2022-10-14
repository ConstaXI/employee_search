#ifndef EMPLOYEE_SEARCH_KEY_H
#define EMPLOYEE_SEARCH_KEY_H

#include <stdlib.h>

typedef struct key {
    int id;
    int position;
} key_t;

key_t *generate_key(int, int);

int find_free_position(key_t *keys, int total);

#endif //EMPLOYEE_SEARCH_KEY_H
