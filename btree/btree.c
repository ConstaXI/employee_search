#include "btree.h"

TNode * main_root = NULL;

TNode * get_main_root() {
    return main_root;
}

void insert(TNode *root, TKey *key) {
    if (root == NULL) {
        root = malloc(sizeof(TNode));
        root->key = key;
        root->left = NULL;
        root->right = NULL;
        main_root = root;
    } else {
        if (key->id < root->key->id) {
            if (root->left == NULL) {
                root->left = malloc(sizeof(TNode));
                root->left->key = key;
                root->left->left = NULL;
                root->left->right = NULL;
            } else {
                insert(root->left, key);
            }
        } else {
            if (root->right == NULL) {
                root->right = malloc(sizeof(TNode));
                root->right->key = key;
                root->right->left = NULL;
                root->right->right = NULL;
            } else {
                insert(root->right, key);
            }
        }
    }
}

void delete(int id) {
    TNode *root = get_main_root();
    TNode *parent = NULL;
    TNode *current = root;

    while (current != NULL) {
        if (current->key->id == id) {
            if (current->left == NULL && current->right == NULL) {
                if (parent == NULL) {
                    main_root = NULL;
                } else {
                    if (parent->left == current) {
                        parent->left = NULL;
                    } else {
                        parent->right = NULL;
                    }
                }
            } else if (current->left == NULL) {
                if (parent == NULL) {
                    main_root = current->right;
                } else {
                    if (parent->left == current) {
                        parent->left = current->right;
                    } else {
                        parent->right = current->right;
                    }
                }
            } else if (current->right == NULL) {
                if (parent == NULL) {
                    main_root = current->left;
                } else {
                    if (parent->left == current) {
                        parent->left = current->left;
                    } else {
                        parent->right = current->left;
                    }
                }
            } else {
                TNode *successor = current->right;
                TNode *successor_parent = current;

                while (successor->left != NULL) {
                    successor_parent = successor;
                    successor = successor->left;
                }

                if (successor_parent->left == successor) {
                    successor_parent->left = successor->right;
                } else {
                    successor_parent->right = successor->right;
                }

                current->key = successor->key;
            }

            free(current);
            return;
        } else if (current->key->id > id) {
            parent = current;
            current = current->left;
        } else {
            parent = current;
            current = current->right;
        }
    }
}

TKey *find(TNode *root, int id) {
    if (root == NULL) {
        return NULL;
    } else if (id < root->key->id) {
        return find(root->left, id);
    } else if (id > root->key->id) {
        return find(root->right, id);
    } else {
        return root->key;
    }
}

void print_btree_keys(TNode *root) {
    if (root == NULL) {
        return;
    } else {
        print_btree_keys(root->left);
        printf("%d ", root->key->id);
        print_btree_keys(root->right);
    }
}
