#ifndef COM112_FILE_H
#define COM112_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "com112_sort.h"

int write_io_file(FILE *fp, const char file_name[], int size, int *array);
FILE *create_report();
void end_report(FILE *fp);
void write_sort_info(FILE *fp, const char *description, sortinfo info, double time);
#endif
