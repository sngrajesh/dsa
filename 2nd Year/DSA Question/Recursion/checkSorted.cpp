#include <iostream>

using namespace std;

bool isSorted(int arr[], int n)
{
    if (n == 0 || n == 1)
        return true;
    return (arr[n] > arr[n - 1]) && isSorted(arr, n - 1);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << isSorted(arr, n) << endl;
    return 0;
}
