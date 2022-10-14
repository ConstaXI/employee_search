#include "key.h"

key_t* generate_key(int id, int position) {
    key_t* key = malloc(sizeof(key_t));
    key->id = id;
    key->position = position;
    return key;
}

int find_free_position(key_t *keys, int total) {
    int prev = keys[0].position;
    int next = keys[1].position;

    if (prev != 0) {
        return 0;
    }

    for (int i = 0; i < total - 1; i++) {
        if (next != prev + 1) {
            return prev + 1;
        }

        prev = keys[i].position;
        next = keys[i + 1].position;
    }

    return total;
}
