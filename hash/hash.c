#include "hash.h"

key_t *create_hash_table(key_t *keys, int total) {
    key_t *hash_table = malloc(sizeof(key_t) * total);
    for (int i = 0; i < total; i++) {
        hash_table[i].id = -1;
        hash_table[i].position = -1;
    }
    for (int i = 0; i < total; i++) {
        int hash = keys[i].id % total;
        while (hash_table[hash].id != -1) {
            hash = (hash + 1) % total;
        }
        hash_table[hash].id = keys[i].id;
        hash_table[hash].position = keys[i].position;
    }
    return hash_table;
}

void print_hash_table(key_t *hash_table, int total) {
    for (int i = 0; i < total; i++) {
        printf("hash position %d: { id %d -> position %d }\n", i, hash_table[i].id, hash_table[i].position);
    }
}
