#include <bits/stdc++.h>
using namespace std;

/*
Initial Array: [5, 3, 8, 4, 2, 7, 1, 6]

1. Choose a pivot (e.g., the last element): Pivot = 6

2. Partition the array around the pivot:
   [5, 3, 4, 2, 1]   |   [6]   |   [8, 7]
    <= pivot         |  pivot  |  > pivot

3. Recursively apply steps 1 and 2 to the left and right partitions:
   [3, 2, 1]   |  [5]  |  [4]   |   [8, 7]
    <= pivot   | pivot | pivot  |   > pivot

   [1, 2]   |   [3]   |  [5]   |  [4]   |   [8, 7]
    <= pivot |  pivot  | pivot | pivot  |   > pivot

   [1] | [2] | [3] | [5] | [4] | [8, 7]
   <    |  <  |  =  |  >  |  <  |   > pivot

   [1] | [2] | [3] | [4] | [5] | [8, 7]
   <    |  <  |  =  |  <  |  >  |   > pivot

4. The array is now sorted: [1, 2, 3, 4, 5, 6, 7, 8]

*/

int Partition(vector<int> &arr, int s, int e)
{
    int pivot = arr[s];
    int count = 0;

    for (int i = s + 1; i <= e; i++)
        if (arr[i] < pivot)
            count++;

    // Placing pivot at correct index
    int pivotIndex = s + count;
    swap(arr[pivotIndex], arr[s]);

    int i = s;
    int j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] < pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i < pivotIndex && j > pivotIndex)
            swap(arr[i++], arr[j--]);
    }

    return pivotIndex;
}

void QuickSort(vector<int> &arr, int s, int e)
{
    // Base Case
    if (s >= e)
        return;
    // Find the pivot element index
    int p = Partition(arr, s, e);
    // making right elemtns of pivot larger than equal to pivot
    QuickSort(arr, s, p - 1);
    // recursively calling the Quick sort fot the left and right part
    QuickSort(arr, p + 1, e);
}

int main(int argc, char const *argv[])
{
    vector<int> arr{10, 80, 30, 90, 40, 50, 70};
    int len = arr.size();

    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;

    QuickSort(arr, 0, len - 1);

    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}