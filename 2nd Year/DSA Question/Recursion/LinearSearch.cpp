#include <iostream>

using namespace std;

int linearSearch(int *arr, int n, int key)
{
    if (n == 0)
        return false;

    if (arr[0] == key)
        return true;

    return linearSearch(arr + 1, n - 1, key);
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Size : ";
    cin >> n;
    int arr[n];
    cout << "Array : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int key;
    cout << "Key : ";
    cin >> key;
    cout << linearSearch(arr, n, key) << endl;
    return 0;
}
