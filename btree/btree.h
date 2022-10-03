#ifndef EMPLOYEE_SEARCH_BTREE_H
#define EMPLOYEE_SEARCH_BTREE_H

#include <stdlib.h>
#include <stdio.h>

#include "../key/key.h"

typedef struct TNode {
    TKey *key;
    struct TNode *left;
    struct TNode *right;
} TNode;

extern TNode * main_root;

TNode *get_main_root();

void create_btree(TKey *keys, int total);

void insert(TNode *root, TKey *key);

TKey *find(TNode *root, int id);

void print_btree_keys(TNode *root);

void delete(int id);

#endif //EMPLOYEE_SEARCH_BTREE_H
