#include <iostream>
using namespace std;
int main()
{

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int m = INT32_MIN;
    for (int i = 0; i < n; i++)
        m = max(m, arr[i]);

    if (m < 0)
    {
        cout << "Not FOunt" << endl;
    }

    bool narr[m];
    for (int i = 0; i < m; i++)
        narr[i] = false;

    for (int i = 0; i < n; i++)
        if (arr[i] >= 0)
            narr[arr[i]] = true;

    for (int i = 0; i < m; i++)
        if (!narr[i])
        {
            cout << i << endl;
            return 0;
        }

    return 0;
}
