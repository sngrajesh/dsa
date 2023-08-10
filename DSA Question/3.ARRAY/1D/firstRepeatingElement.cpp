
#include <iostream>
using namespace std;

// 0 < N < 10^6 -> time -> O(n) or O(n^2)

int firstRepeatingElement(int arr[], int n, int m)
{
    int ind[m];
    for (int i = 0; i < m; i++)
        ind[i] = -1;

    int mn = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        if (ind[arr[i]] != -1)
        {
            mn = min(mn, ind[arr[i]]);
        }
        else
        {
            ind[arr[i]] = i;
        }
    }

    return (mn == INT32_MAX) ? -1 : (mn + 1);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int m = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        m = max(m, arr[i]);
    }

    cout << firstRepeatingElement(arr, n, m) << endl;
    return 0;
}