#ifndef EMPLOYEE_SEARCH_BTREE_H
#define EMPLOYEE_SEARCH_BTREE_H

#include <stdlib.h>
#include <stdio.h>

#include "../key/key.h"

typedef struct TNode {
    key_t *key;
    struct TNode *left;
    struct TNode *right;
} TNode;

extern TNode * main_root;

TNode *get_main_root();

void create_btree(key_t *keys, int total);

void insert(TNode *root, key_t *key);

key_t *find(TNode *root, int id);

void print_btree_keys(TNode *root);

void delete(int id);

#endif //EMPLOYEE_SEARCH_BTREE_H
