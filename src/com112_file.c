#include "com112_file.h"

int write_file(FILE* fp, const char file_name[], char *buffer) {
    fp = fopen(file_name, "w");
    if (fp) {
        for (int i = 0; i < strlen(buffer); ++i) {
            putc(buffer[i], fp);
        }
        return 1;
    }
    else {
        return 0;
    }
}
