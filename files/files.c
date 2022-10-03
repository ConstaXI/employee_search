#include "files.h"

int TOTAL_REGISTERS = 100;

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

void *write_data(char *filename, void *data, int total, size_t size_of_type) {
    FILE *file;

    file = fopen(filename, "wb");

    if (file == NULL) exit(1);

    void *allocated = malloc(size_of_type * total);

    if (fwrite(data, size_of_type, total, file) != total)
        exit(1);

    if (fclose(file) == EOF) exit(1);

    return allocated;
}
