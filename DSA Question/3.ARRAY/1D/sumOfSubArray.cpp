#include <iostream>
using namespace std;
// A subarray is a contiguous part of array, i.e., Subarray is an array that is inside another array.

void printSubArraySum(int arr[], int n)
{

    int tempSum = 0;
    for (int i = 0; i < n; i++)
    {
        tempSum = 0;
        for (int j = i; j < n; j++)
        {
            tempSum += arr[j];
            cout << tempSum << " ";
        }
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    printSubArraySum(arr, n);
    return 0;
}