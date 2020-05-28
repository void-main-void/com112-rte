#include <stdio.h>
#include <stdlib.h>

#include "com112_file.h"
#include "com112_sort.h"

int power(int x, int y);
int menu();
int relatorio();
int *char_to_int(char *buffer);

int main(int argc, char const *argv[]) {
	int array[] = { 3, 9, 1, 4, 6, 6, 16 };
	selection_sort(array, 7);

	return 0;
}

int power(int x, int y) {
	int power = 1;
	if (x == 0) return 0;
	if (y == 0) return 1;
	while (y-- > 0) {
		power *= x;
	}
	return power;
}

int menu() {
	int op = 0;
	do {	
		printf(" 1. Bubble Sort\n");
		printf(" 2. Selection Sort\n");
		printf(" 3. Insertion Sort\n");
		printf(" 4. Relatorio\n");
		printf("-1. Sair\n");
		scanf("%d", &op);

		switch (op) {
			case 1: {
				printf("OP = %d!\n", op);
			} break;
			case 2: {
				printf("OP = %d!\n", op);
			} break;
			case 3: {
				printf("OP = %d!\n", op);
			} break;
			case -1: {
			} break;
			default: {
				op = -1;
			} break;
		}
	} while (op != -1);
}

int *char_to_int(char *buffer) {
	int *int_array = 0;
	int size = 0;
	int k = 0;
	for (int i = 0; i < strlen(buffer); ++i) {
		if (buffer[i] == '\n') {
			for (int j = i - 1; j >= 0; --j) {
				size += (int)(buffer[j] - '0') * power(10, i - j - 1);
			}
			int_array = calloc(size, sizeof(int));
		}
		if (int_array && buffer[i] != ' ' && buffer[i] != '\n') {
			int_array[k++] = (int)(buffer[i] - '0');
		}
	}
	return int_array;
}
