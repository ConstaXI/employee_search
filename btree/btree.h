#ifndef EMPLOYEE_SEARCH_BTREE_H
#define EMPLOYEE_SEARCH_BTREE_H

#include "../employee/employee.h"
#include "../files/files.h"

typedef struct TNode {
    TKey *key;
    struct TNode *left;
    struct TNode *right;
} TNode;

TNode *get_main_root();

void insert(TNode *root, TKey *key);

TKey *find(TNode *root, int id);

void print_btree_keys(TNode *root);

void delete(int id);

#endif //EMPLOYEE_SEARCH_BTREE_H
