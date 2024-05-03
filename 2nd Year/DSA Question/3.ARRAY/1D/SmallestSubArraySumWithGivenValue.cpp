/*
arr[] = {1, 4, 45, 6, 0, 19}
   x  =  51
Output: 3
Minimum length subarray is {4, 45, 6}

arr[] = {1, 10, 5, 2, 7}
   x  = 9
Output: 1
Minimum length subarray is {10}

arr[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250}
    x = 280
Output: 4
Minimum length subarray is {100, 1, 0, 200}

arr[] = {1, 2, 4}
    x = 8
Output : Not Possible
Whole array sum is smaller than 8.
*/
#include <iostream>
using namespace std;

void subArraySum(int arr[], int n, int x)
{

    int result = n + 1;

    for (int i = 0; i < n; i++)
    {

        int sum = arr[i];

        if (sum > x)
        {
            cout << 1 << endl;
            return;
        }

        for (int j = i + 1; j < n; j++)
        {

            sum += arr[j];

            if ((sum > x) && ((j - i + 1) < result))
                result = (j - i + 1);
        }
    }

    if (result == (n + 1))
    {
        cout << "Not possible" << endl;
        return;
    }
    else
    {
        cout << result;
    }
}

int main()
{
    int n = 0;

    int arr1[] = {1, 4, 45, 6, 0, 19};
    int x1 = 51;
    n = sizeof(arr1) / sizeof(arr1[0]);
    subArraySum(arr1, n, x1);

    int arr2[] = {1, 10, 5, 2, 7};
    int x2 = 9;
    n = sizeof(arr2) / sizeof(arr2[0]);
    subArraySum(arr2, n, x2);

    int arr3[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
    int x3 = 280;
    n = sizeof(arr3) / sizeof(arr3[0]);
    subArraySum(arr3, n, x3);

    int arr4[] = {1, 2, 4};
    int x4 = 8;
    n = sizeof(arr4) / sizeof(arr4[0]);
    subArraySum(arr4, n, x4);

    return 0;
}
