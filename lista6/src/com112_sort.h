#ifndef COM112_SORT_H
#define COM112_SORT_H

#include <stdlib.h>

typedef struct sortinfo_t {
    int comparisons;
    int swaps;
} sortinfo;

void swap(int *a, int *b);
sortinfo bubble_sort(int array[], int size);
sortinfo selection_sort(int array[], int size);
sortinfo insertion_sort(int array[], int size);
sortinfo merge_sort(int array[], int size, int begin, int end);
sortinfo merge(int array[], int size, int begin, int middle, int end);
sortinfo quick_sort(int array[], int begin, int end);
int partition(int array[], int begin, int end, sortinfo* info);

#endif
