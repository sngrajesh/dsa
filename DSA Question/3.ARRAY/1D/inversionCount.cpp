#include <iostream>
using namespace std;
int countInversion(int arr[], int n)
{
	int count = 0;
	for (int a = 0; a < n - 1; a++)
	{
		for (int b =1 ; b < n; b++)
		{
			if (arr[a] > arr[b])
			{
				/*
				int t = arr[a];
				arr[a] = arr[b] ;
				arr[b] = t;
				*/
				count++;
			}
		}
	}
	return count;
}

int inversionCount(int A[], int size)
{
	int inversion_count = 0;
	for (int i = 0; i < size - 1; i = i + 1)
	{
		for (int j = i + 1; j < size; j = j + 1)
		{
			if (A[j] < A[i])
				inversion_count = inversion_count + 1;
		}
	}
	return inversion_count;
}

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	int arr[n];
	for (int a = 0; a < n; a++)
		cin >> arr[a];

	cout << inversionCount(arr, n);
	return 0;
}