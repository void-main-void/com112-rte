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

FILE *create_report(FILE *fp, int size) {
    fp = fopen("com112_relatorio.txt", "w");
    fprintf(fp, "Número de elementos ordenados: %d\n", size);
    return fp;
}

void end_report(FILE *fp) {
    fclose(fp);
}

void write_sort_info(FILE *fp, const char *description, sortinfo info, double time) {
    fprintf(fp, description);
    fprintf(fp, "\tTempo de execução: %f.\n", time);
    fprintf(fp, "\tNúmero de comparações: %d.\n", info.comparisons);
    fprintf(fp, "\tNúmero de movimentações: %d.\n", info.swaps);
}
