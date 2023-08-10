// C++ code to find
// duplicates in O(n) time

#include <stdio.h>
#include <iostream>
#include <limits>
using namespace std;
//METHOD 1
/*
int main(int argc, char *argv[])
{
	int n;
	int m = INT_MIN;
	printf("ENTER : ");
	scanf("%d", &n);
	int arr[n];
	for (int j = 0; j < n; j++)
	{
		printf("%d>>", j + 1);
		cin >> arr[j];
		if (arr[j] > m)
		{
			m = arr[j];
		}
	}
	int arr2[10000] = {0};
	for (int j = 0; j < n; j++)
	{
		if (arr2[arr[j]] == 1)
		{
			cout << arr[j];
			arr2[arr[j]] = 2;
		}
		else
		{
			arr2[arr[j]] = 1;
		}
	}
	return 0;
}
*/

//METHOD 2



// Function to print duplicates
void printRepeating(int arr[], int size)
{
    int i;
    cout << "The repeating elements are:" << endl;
    for (i = 0; i < size; i++) {
        if (arr[abs(arr[i])] >= 0)
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        else
            cout << abs(arr[i]) << " ";
    }
}
int main()
{
    int arr[] = { 1, 2, 3, 1, 3, 6, 6 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    printRepeating(arr, arr_size);
    return 0;
}