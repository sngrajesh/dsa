#include <bits/stdc++.h>
using namespace std;

void BubbleSort(vector<int> &arr, int n)
{
    if (n <= 1)
        return;

    int i = 0;
    while (i < n)
    {
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
        i++;
    }
    BubbleSort(arr, n - 1);
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Size : ";
    cin >> n;

    vector<int> nums(n);
    cout << "Array : ";

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    BubbleSort(nums, n);

    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";

    return 0;
}