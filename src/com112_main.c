#include "com112_file.h"
#include "com112_sort.h"
#include <time.h>

#define MIN_ARRAY_SIZE 5000
#define MAX_RAND_SIZE 10000
// TOTAL SIZE = RAND % MAX_RAND_SIZE + MIN_ARRAY_SIZE

int menu();
int relatorio();
int *create_array(int size);
int *copy_array(int *array, int size);
int main(int argc, char const *argv[]) {
	srand(time(0));
	int size = 0;
	size = (rand() % MAX_RAND_SIZE) + MIN_ARRAY_SIZE;
	int *array = 0;
	array = create_array(size);
	int op = -1;
	FILE *fp = 0;
	do {
		menu();
		scanf("%d", &op);
		switch (op) {
			case 1: {
				int *bubble_array = copy_array(array, size);
			    bubble_sort(bubble_array, size);
				write_io_file(fp, "com112_entrada.txt", size, array);
				write_io_file(fp, "com112_saida.txt", size, bubble_array);
				free(bubble_array);
				bubble_array = 0;
			} break;
			case 2: {
				int *selection_array = copy_array(array, size);
				selection_sort(selection_array, size);
				write_io_file(fp, "com112_entrada.txt", size, array);
				write_io_file(fp, "com112_saida.txt", size, selection_array);
				free(selection_array);
				selection_array = 0;
			} break;
			case 3: {
				int *insertion_array = copy_array(array, size);
				selection_sort(insertion_array, size);
				write_io_file(fp, "com112_entrada.txt", size, array);
				write_io_file(fp, "com112_saida.txt", size, insertion_array);
				free(insertion_array);
				insertion_array = 0;
			} break;
		}
	} while (op != -1);
	free(array);
	if (fp) fclose(fp);
	fp = 0;
	array = 0;
	return 0;
}

int menu() {
	printf(" 1. Bubble sort\n");
	printf(" 2. Selection sort\n");
	printf(" 3. Insertion sort\n");
	printf(" 4. Relatorio\n");
	printf("-1. Sair\n");
	return 1;
}

int relatorio() {
	return 1;
}

int *create_array(int size) {
	int *array = calloc(size, sizeof(int));
	if (array) {
		for (int i = 0; i < size; ++i) {
			array[i] = rand() % size;
		}
		return array;
	}
	return 0;
}

int *copy_array(int *array, int size) {
	int *copy = 0;
	copy = calloc(size, sizeof(int));
	for (int i = 0; i < size; ++i) {
		copy[i] = array[i];
	}
	return copy;
}

