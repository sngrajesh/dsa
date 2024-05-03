https://www.naukri.com/code360/problems/build-min-heap_1171167

#include <bits/stdc++.h>

// For max heap
void heapify(vector<int> &arr, int size, int index) {
  int smallest = index;
  int left = 2 * index + 1;
  int right = 2 * index + 2;

  if (left < size && arr[smallest] > arr[left])
    smallest = left;
  if (right < size && arr[smallest] > arr[right])
    smallest = right;

  if (smallest != index) {
    swap(arr[smallest], arr[index]);
    heapify(arr, size, smallest);
  }
}

vector<int> buildMinHeap(vector<int> &arr) {
  int size = arr.size();
  for (int i = size / 2 - 1; i >= 0; i--)
    heapify(arr, size, i);
  return arr;
}
