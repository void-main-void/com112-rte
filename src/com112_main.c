#include "com112_file.h"
#include "com112_sort.h"
#include <time.h>

#define MIN_ARRAY_SIZE 0
#define MAX_RAND_SIZE 10000
// TOTAL SIZE = RAND % MAX_RAND_SIZE + MIN_ARRAY_SIZE

int menu();
int relatorio();
int *create_array(int size);
int *copy_array(int *array, int size);
void write_report(FILE *fp, int array[], int size);
void print_report(const char *description, sortinfo info, double time);
int main(int argc, char const *argv[]) {
	srand(time(0));
	int size = 0;
	size = 10000;
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
			case 4: {
				int *merge_array = copy_array(array, size);
				merge_sort(merge_array, size, 0, size - 1);
				write_io_file(fp, "com112_entrada.txt", size, array);
				write_io_file(fp, "com112_saida.txt", size, merge_array);
				free(merge_array);
				merge_array = 0;
			} break;
			case 5: {
				int *quick_array = copy_array(array, size);
				quick_sort(quick_array, 0, size - 1);
				write_io_file(fp, "com112_entrada.txt", size, array);
				write_io_file(fp, "com112_saida.txt", size, quick_array);
				free(quick_array);
				quick_array = 0;
			} break;
			case 6: {
				write_report(fp, array, size);
			} break;
			case 7:
			default: {
				op = -1;
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
	printf("1. Bubble sort\n");
	printf("2. Selection sort\n");
	printf("3. Insertion sort\n");
	printf("4. Merge sort\n");
	printf("5. Quick sort\n");
	printf("6. Relatorio\n");
	printf("7. Sair\n");
	return 1;
}

int relatorio() {
	return 1;
}

int *create_array(int size) {
	int *array = calloc(size, sizeof(int));
	if (array) {
		for (int i = 0; i < size; ++i) {
			array[i] = rand() % size; // Aleatório
			// array[i] = i;             // Crescente
			// array[i] = size - 1 - i;  // Decrescente
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

void write_report(FILE *fp, int array[], int size) {
	if (fp) { fclose(fp); }
	double bubble_time, selection_time, insertion_time, merge_time, quick_time;
	int *bubble_array, *selection_array, *insertion_array, *merge_array, *quick_array;
	bubble_array = selection_array = insertion_array = merge_array = quick_array = 0;
	bubble_array = copy_array(array, size);
	selection_array = copy_array(array, size);
	insertion_array = copy_array(array, size);
	merge_array = copy_array(array, size);
	quick_array = copy_array(array, size);
	fp = create_report(fp, size);
	write_io_file(fp, "com112_entrada.txt", size, array);
	clock_t begin = clock();
	sortinfo bubble_info = bubble_sort(bubble_array, size);
	clock_t end = clock();
	bubble_time = (double) (end - begin) / CLOCKS_PER_SEC;
	begin = clock();
	sortinfo selection_info = selection_sort(selection_array, size);
	end = clock();
	selection_time = (double) (end - begin) / CLOCKS_PER_SEC;
	begin = clock();
	sortinfo insertion_info = insertion_sort(insertion_array, size);
	end = clock();
	insertion_time = (double) (end - begin) / CLOCKS_PER_SEC;
	begin = clock();
	sortinfo merge_info = merge_sort(merge_array, size, 0, size - 1);
	end = clock();
	merge_time = (double) (end - begin) / CLOCKS_PER_SEC;
	begin = clock();
	sortinfo quick_info = quick_sort(quick_array, 0, size - 1);
	end = clock();
	quick_time = (double) (end - begin) / CLOCKS_PER_SEC;
	printf("Número de elementos ordenados: %d\n", size);
	print_report("Método Bubble Sort\n", bubble_info, bubble_time);
	print_report("Método Selection Sort\n", selection_info, selection_time);
	print_report("Método Insertion Sort\n", insertion_info, insertion_time);
	print_report("Método Merge Sort\n", merge_info, merge_time);
	print_report("Método Quick Sort\n", quick_info, quick_time);
	write_sort_info(fp, "Método Bubble Sort\n", bubble_info, bubble_time);
	write_sort_info(fp, "Método Selection Sort\n", selection_info, selection_time);
	write_sort_info(fp, "Método Insertion Sort\n", insertion_info, insertion_time);
	write_sort_info(fp, "Método Merge Sort\n", merge_info, merge_time);
	write_sort_info(fp, "Método Quick Sort\n", quick_info, quick_time);
	write_io_file(fp, "com112_saida.txt", size, quick_array);
	end_report(fp);
	free(quick_array);
	free(merge_array);
	free(insertion_array);
	free(selection_array);
	free(bubble_array);
	quick_array = 0;
	merge_array = 0;
    insertion_array = 0;
    selection_array = 0;
    bubble_array = 0;
}

void print_report(const char *description, sortinfo info, double time) {
	printf(description);
	printf("\tTempo de execução: %f.\n", time);
	printf("\tNúmero de comparações: %d.\n", info.comparisons);
	printf("\tNúmero de movimentações: %d.\n", info.swaps);
}
