#include "com112_file.h"
#include <stdlib.h>

char *read_file(const char file_name[]) {
    FILE *pFile = fopen(file_name, "r");
    char *buffer = 0;
    if (pFile) {
        if (!fseek(pFile, 0L, SEEK_END)) {
            long buffer_size = ftell(pFile);
            if (buffer_size != -1) {
                buffer = calloc(buffer_size + 1, sizeof(char));
                if (!fseek(pFile, 0L, SEEK_SET)) {
                    size_t new_length = fread(buffer, sizeof(char), buffer_size, pFile);
                    if (ferror(pFile)) {
                        fputs("Cannot read file!", stderr);
                    } else {
                        buffer[new_length++] = '\0';
                    }
                }
            }
        }
    }
    fclose(pFile);
    return buffer;
}
