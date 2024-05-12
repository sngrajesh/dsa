// For max heap
void heapify(int arr[], int size, int index) {
    int laegest = index;
    int left = 2 * index;
    int right = 2 * index + 1;

    if (left <= size && arr[laegest] < arr[left]) laegest = left;
    if (right <= size && arr[laegest] < arr[right]) laegest = right;

    if (laegest != index) {
        swap(arr[laegest], arr[index]);
        heapify(arr, size, laegest);
    }
}

// Heap Sort
void heapSort(int arr[], int size) {
    // Build max heap
    for (int i = size / 2; i > 0; i--) {
        heapify(arr, size, i);
    }

    // Perform heap sort
    for (int i = size; i > 1; i--) {
        swap(arr[1], arr[i]);
        heapify(arr, i - 1, 1);
    }
}
