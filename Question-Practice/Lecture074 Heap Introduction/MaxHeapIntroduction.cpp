#include <bits/stdc++.h>
using namespace std;

// Max Heap
class Heap {
   public:
    int arr[100];
    int size = 0;

    void insert(int data) {
        if (size >= 100) {
            cout << "Heap is already full" << endl;
            return;
        }
        size = size + 1;
        int index = size;
        arr[index] = data;

        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    int remove() {
        if (size <= 0) {
            cout << "Heap is already empty" << endl;
            return -1;
        }

        int ans = arr[1];
        arr[1] = arr[size];
        size = size - 1;

        int index = 1;
        while (index <= size) {
            int left = 2 * index;
            int right = 2 * index + 1;

            if ((left < size) && (arr[left] > arr[index]) &&
                (arr[left] > arr[right])) {
                swap(arr[left], arr[index]);
                index = left;
            } else if ((right < size) && (arr[right] > arr[index]) &&
                       (arr[left] < arr[right])) {
                swap(arr[right], arr[index]);
                index = right;
            } else {
                return ans;
            }
        }
        return ans;
    }

    void print() {
        for (int i = 1; i <= size; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

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

int main(int argc, char const *argv[]) {
    Heap h;
    h.insert(4);
    h.insert(5);
    h.insert(3);
    h.insert(10);
    h.insert(1);
    h.insert(6);
    h.insert(12);
    h.insert(9);
    h.insert(15);
    h.print();
    //          15
    //        /  \
    //       12   10
    //      / \   / \
    //     9   1 3   6
    //    / \
    //   4   5
    h.remove();
    h.print();
    //         12
    //        /  \
    //       9    10
    //      / \   / \
    //     5   1 3   6
    //    /
    //   4

    int arr[] = {-1, 54, 53, 55, 52, 50};
    int size = 5;

    cout << endl;
    for (int i = 1; i <= size; i++) cout << arr[i] << " ";

    for (int i = size / 2; i > 0; i--) heapify(arr, size, i);
    cout << endl;

    for (int i = 1; i <= size; i++) cout << arr[i] << " ";
    cout << endl;

    int arrHS[] = {-1, 54, 53, 55, 52, 50};
    // Sorting array
    heapSort(arrHS, size);

    for (int i = 1; i <= size; i++) cout << arrHS[i] << " ";
    cout << endl;
    return 0;
}