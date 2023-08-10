#include <stdio.h>
#include <iostream>
#include <limits>
using namespace std;
int longestSubArrSum(int arr[], int n)
{
	int max = INT_MIN;
	int csum = 0;
	for (int j = 0; j < n; j++)
	{
		csum += arr[j];
		if (csum > max)
		{
			max = csum;
		}
		if (csum < 0)
		{
			csum = 0;
		}
	}

	return max;
}

int main(int argc, char *argv[])
{
	int n;
	int min = INT_MAX;
	int max = INT_MIN;
	printf("ENTER : ");
	scanf("%d", &n);
	int arr[n];
	for (int j = 0; j < n; j++)
	{
		printf("%d>>", j + 1);
		cin >> arr[j];
	}
	cout << longestSubArrSum(arr, n);
	return 0;
}