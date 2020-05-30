#include "com112_sort.h"

void swap(int *a, int *b) {
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

sortinfo bubble_sort(int array[], int size) {
    sortinfo counter;
    counter.comparisons = counter.swaps = 0;
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (array[j] < array[i]) {
                swap(&array[i], &array[j]);
                ++counter.swaps;
            }
            ++counter.comparisons;
        }
    }
    return counter;
}

sortinfo selection_sort(int array[], int size) {
    int min_index = 0;
    sortinfo counter;
    for (int i = 0; i < size - 1; ++i) {
        min_index = i;
        for (int j = i + 1; j < size; ++j) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
            ++counter.comparisons;
        }
        swap(&array[i], &array[min_index]);
        ++counter.swaps;
    }
    return counter;
}

sortinfo insertion_sort(int array[], int size) {
    int key = 0;
    int j = 0;
    sortinfo counter;
    counter.comparisons = counter.swaps = 0;
    for (int i = 1; i < size; ++i) {
        key = array[i];
        j = i - 1;
        while (j >= 0 && key < array[j]) {
            array[j + 1] = array[j];
            ++counter.swaps;
            --j;
        }
        ++counter.comparisons;
        array[j + 1] = key;
        ++counter.swaps;
    }
    return counter;
}
