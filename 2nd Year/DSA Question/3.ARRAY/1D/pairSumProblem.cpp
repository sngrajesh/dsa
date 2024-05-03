#include <bits/stdc++.h>
using namespace std;

bool pairSumInOofN2(int arr[], int n, int k)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] + arr[j] == k)
            {
                cout << i << "  " << j << endl;
                return true;
            }
    return false;
}

bool pairSumInOofNlogN(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (arr[i] + arr[j] == k)
        {
            cout << i << "  " << j << endl;
            return true;
        }
        else if (arr[i] + arr[j] < k)
            i++;
        else
            j--;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k;
    cin >> k;
    pairSumInOofN2(arr, n, k);
    pairSumInOofNlogN(arr, n, k);

    return 0;
}