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

sortinfo merge_sort(int array[], int size, int begin, int end) {
    int middle = 0;
    sortinfo info;
    if (begin < end) {
        middle = (begin + end) / 2;
        merge_sort(array, size, begin, middle);
        merge_sort(array, size, middle + 1, end);
        info = merge(array, size, begin, middle, end);
    } else {
        return info;
    }
}

sortinfo merge(int array[], int size, int begin, int middle, int end) {
    sortinfo info;
    info.comparisons = info.swaps = 0;
    int v1 = begin;
    int v2 = middle + 1;
    int aux = begin;
    int *aux_array = 0;
    aux_array = calloc(size - 1, sizeof(int));
    do {
        ++info.comparisons;
        if (array[v1] <= array[v2]) {
            aux_array[aux++] = array[v1++];
        } else {
            aux_array[aux++] = array[v2++];
        }
    } while (v1 <= middle && v2 <= end);
    while (v1 <= middle) {
        ++info.swaps;
        aux_array[aux++] = array[v1++];
    }
    while (v2 <= end) {
        ++info.swaps;
        aux_array[aux++] = array[v2++];
    }
    for (int i = begin; i <= end; ++i) {
        ++info.swaps;
        array[i] = aux_array[i];
    }
    return info;
    free(aux_array);
    aux_array = 0;
}
