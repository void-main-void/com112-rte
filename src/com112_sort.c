void swap(int *a, int *b) {
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int array[], int size) {
    int swapped = 0;
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (array[j] < array[i]) {
                swap(&array[i], &array[j]);
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
    }
}
