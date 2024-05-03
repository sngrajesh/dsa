#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int start, int end, int key)
{
    if (start > end)
        return -1;
    int mid = start + (end - start) / 2;
    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return binarySearch(arr, mid + 1, end, key);
    else
        return binarySearch(arr, start, mid - 1, key);
}

int search(vector<int> &nums, int target)
{
    return binarySearch(nums, 0, nums.size(), target);
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Size : ";
    cin >> n;
    vector<int>nums(n);
    cout << "Array : ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int key;
    cout << "Key : ";
    cin >> key;

    cout << "Position : " << search(nums, key) << endl;
    return 0;
}
