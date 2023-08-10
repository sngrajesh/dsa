#include <iostream>
using namespace std;

/*******************************************************************************
arr         = [  4  -4  6  -6  10  -11  12  ]
nonWrapSum  =                           |\\\|  = 12
wrapSum     = |\\\\\\\\\\\\\\\\\\|      |\\\|  = 22 = totalSum - (-kadens(-arr))
totalSum    = |\\\\\\\\\\\\\\\\\\\\\\\\\\\\\|  = 11
kadens(-arr)=                     |\\\|        = 11

final = max(wrapSum , N==nonWrapSum) = 2
*******************************************************************************/

int kadens(int arr[], int n)
{
    int currentSum = 0;
    int maxSum = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        currentSum += arr[i];
        maxSum = max(maxSum, currentSum);
        if (currentSum < 0)
            currentSum = 0;
    }
    return maxSum;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int nonWrapSum = kadens(arr, n);
    int wrapSum;
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
        arr[i] = -arr[i];
    }
    wrapSum = totalSum + kadens(arr, n);

    cout << max(wrapSum, nonWrapSum) << endl;
    return 0;
}