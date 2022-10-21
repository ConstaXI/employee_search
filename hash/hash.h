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

chain_hash_t *create_chained_hash_table(key_t *keys, int hash_table_size, int keys_size);

void print_chained_hash_table(chain_hash_t *chained_key, int total);

#endif //EMPLOYEE_SEARCH_HASH_H
