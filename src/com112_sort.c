void bubble_sort(int array[], int size) {
    int foo = 0;
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (array[j] < array[i]) {
                foo = array[j];
                array[j] = array[i];
                array[i] = foo;
            }
        }
    }
}
