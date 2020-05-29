void swap(int *a, int *b) {
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

int *bubble_sort(int array[], int size) {
    int counter[2] = { 0 }; // 0 = swaps  ||  1 = comparisons
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (array[j] < array[i]) {
                swap(&array[i], &array[j]);
                ++counter[0];
                ++counter[1];
            }
        }
    }
    return counter;
}

int *selection_sort(int array[], int size) {
    int min_index = 0;
    int counter[2] = { 0 }; // 0 = swaps  ||  1 = comparisons
    for (int i = 0; i < size - 1; ++i) {
        min_index = i;
        for (int j = i + 1; j < size; ++j) {
            if (array[j] < array[min_index]) {
                min_index = j;
                ++counter[1];
            }
        }
        swap(&array[i], &array[min_index]);
        ++counter[0];
    }
    return counter;
}

int *insertion_sort(int array[], int size) {
    int key = 0;
    int j = 0;
    int counter[2] = { 0 }; // 0 = swaps  ||  1 = comparisons
    for (int i = 1; i < size; ++i) {
        key = array[i];
        j = i - 1;
        while (j >= 0 && key < array[j]) {
            array[j + 1] = array[j];
            ++counter[0];
            ++counter[1];
            --j;
        }
        array[j + 1] = key;
        ++counter[0];
    }
    return counter;
}
