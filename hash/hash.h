#ifndef EMPLOYEE_SEARCH_HASH_H
#define EMPLOYEE_SEARCH_HASH_H

#include "stdio.h"

#include "../key/key.h"

typedef struct chain_hash {
    key_t key;
    struct chain_hash *next;
} chain_hash_t;

void print_hash_table(key_t *hash_table, int total);

key_t *create_hash_table(key_t *keys, int total);

#endif //EMPLOYEE_SEARCH_HASH_H
