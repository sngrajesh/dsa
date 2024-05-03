#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
int main(int argc, char *argv[])
{
	int n;
	printf("Center number of element : ");
	scanf("%d", &n);
	int arr[n];
	for (int I = 0; I < n; I++)
	{
		cout << ">>";
		cin >> arr[I];
	}
	insertionSort(arr, n);
	for (int I = 0; I < n; I++)
	{
		cout << arr[I] << " ";
	}

	return 0;
}