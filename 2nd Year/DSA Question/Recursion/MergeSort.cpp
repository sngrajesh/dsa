// MergeSort.cpp

// https://www.codingninjas.com/studio/problems/merge-sort_920442?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_14
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int s, int m, int e)
{
    int l1 = m - s + 1;
    int l2 = e - m;

    vector<int> arr1(l1);
    vector<int> arr2(l2);

    int k = s;
    for (int i = 0; i < l1; i++)
        arr1[i] = arr[k++];

    k = m + 1;
    for (int i = 0; i < l2; i++)
        arr2[i] = arr[k++];

    k = s;
    int i1 = 0;
    int i2 = 0;

    while (i1 < l1 && i2 < l2)
    {
        if (arr1[i1] < arr2[i2])
            arr[k++] = arr1[i1++];
        else
            arr[k++] = arr2[i2++];
    }

    while (i1 < l1)
        arr[k++] = arr1[i1++];

    while (i2 < l2)
        arr[k++] = arr2[i2++];
}

void MergeSortWithNewArray(vector<int> &arr, int s, int e)
{
    if (e <= s)
        return;
    int m = s + (e - s) / 2;
    MergeSortWithNewArray(arr, s, m);
    MergeSortWithNewArray(arr, m + 1, e);
    merge(arr, s, m, e);
}

void mergeSort(vector<int> &arr, int n)
{
    MergeSortWithNewArray(arr, 0, n - 1);
}
int main(int argc, char const *argv[])
{
    vector<int> arr{
        13,
        12,
        11,
        10,
        9,
        8,
        7,
        6,
        5,
        4,
        3,
        2,
        1,
    };
    mergeSort(arr, 13);
    for (int i = 0; i < 13; i++)
        cout << arr[i] << " ";

    return 0;
}