#include "files.h"

void *read_data(char *filename, int total, size_t size_of_type) {
    FILE *file;

    file = fopen(filename, "rb");

    if (file == NULL) exit(1);

    void *data = malloc(size_of_type * total);

    if (fread(data, size_of_type, total, file) != total) exit(1);

    if (fclose(file) == EOF) {
        free(data);
        exit(1);
    }

    return data;
}

void *read_target(char *filename, int target, size_t size_of_type) {
    FILE *file;

    file = fopen(filename, "rb");

    if (file == NULL) exit(1);

    void *data = malloc(size_of_type);

    if (fseek(file, target * size_of_type, SEEK_SET) != 0) exit(1);

    if (fread(data, size_of_type, 1, file) != 1) exit(1);

    if (fclose(file) == EOF) {
        free(data);
        exit(1);
    }

    return data;
}

void write_keys(char *filename, TKey *keys, int total) {
    FILE *file;

    file = fopen(filename, "wb");

    if (file == NULL) exit(1);

    if (fwrite(keys, sizeof(TKey), total, file) != total)
        exit(1);

    if (fclose(file) == EOF) exit(1);
}

TKey* write_employees(char *filename, TEmployee *data, int total) {
    FILE *file;

    file = fopen(filename, "wb");

    if (file == NULL) exit(1);

    TKey * keys = malloc(sizeof(TKey) * total);

    for (int i = 0; i < total; i++) {
        keys[i].cod = data[i].cod;
        keys[i].key = i;
    }

    write_keys("employees_keys.bin", keys, total);

    if (fwrite(data, sizeof(TEmployee), total, file) != total)
        exit(1);

    if (fclose(file) == EOF) exit(1);

    return keys;
}
