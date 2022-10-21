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

chain_hash_t *create_chained_hash_table(key_t *keys, int hash_table_size, int keys_size) {
    chain_hash_t *hash_table = malloc(sizeof(chain_hash_t) * hash_table_size);
    for (int i = 0; i < hash_table_size; i++) {
        hash_table[i].key.id = -1;
        hash_table[i].key.position = -1;
        hash_table[i].next = NULL;
    }
    for (int i = 0; i < keys_size; i++) {
        int hash = keys[i].id % hash_table_size;
        if (hash_table[hash].key.id == -1) {
            hash_table[hash].key.id = keys[i].id;
            hash_table[hash].key.position = keys[i].position;
        } else {
            chain_hash_t *new_node = malloc(sizeof(chain_hash_t));
            new_node->key.id = keys[i].id;
            new_node->key.position = keys[i].position;
            new_node->next = NULL;
            chain_hash_t *current = &hash_table[hash];
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = new_node;
        }
    }
    return hash_table;
}

void print_hash_table(key_t *hash_table, int total) {
    for (int i = 0; i < total; i++) {
        printf("hash position %d: { id %d -> position %d }\n", i, hash_table[i].id, hash_table[i].position);
    }
}

void print_chained_hash_table(chain_hash_t *chained_key, int total) {
    for (int i = 0; i < total; i++) {
        printf("hash position %d: { id %d -> position %d }", i, chained_key[i].key.id, chained_key[i].key.position);
        chain_hash_t *current = chained_key[i].next;
        while (current != NULL) {
            printf(" -> { id %d -> position %d }\n", current->key.id, current->key.position);
            current = current->next;
        }
        printf("\n");
    }
}
