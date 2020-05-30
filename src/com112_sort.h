#ifndef COM112_SORT_H
#define COM112_SORT_H

typedef struct sortinfo_t {
    int comparisons;
    int swaps;
} sortinfo;

void swap(int *a, int *b);
sortinfo bubble_sort(int array[], int size);
sortinfo selection_sort(int array[], int size);
sortinfo insertion_sort(int array[], int size);

#endif
