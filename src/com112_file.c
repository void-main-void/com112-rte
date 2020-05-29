#include "com112_file.h"

int write_io_file(FILE *fp, const char file_name[], int size, int *array) {
    fp = fopen(file_name, "w");
    if (!fp) { return 0; }
    fprintf(fp, "%d\n", size);
    for (int i = 0; i < size; ++i) {
        fprintf(fp, "%d ", array[i]);
    }
    fclose(fp);
    fp = 0;
    return 1;
}
