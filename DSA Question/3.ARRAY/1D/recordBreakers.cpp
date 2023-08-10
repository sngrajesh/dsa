#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = 0;
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max && i == n - 1)
        {
            ans++;
        }
        if (arr[i] > max && arr[i] > arr[i + 1])
        {
            ans++;
            max = arr[i];
        }
    }
    cout << ans << endl;
    return 0;
}   