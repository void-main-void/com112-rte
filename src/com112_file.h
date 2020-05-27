#ifndef COM112_FILE_H
#define COM112_FILE_H

#include <stdio.h>
#include <string.h>

char *read_file(const char file_name[]);
void write_file(const char file_name[], char *buffer);

#endif
