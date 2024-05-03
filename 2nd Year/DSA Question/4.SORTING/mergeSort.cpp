#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;
void merge(int arr[], int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;

	int L[n1], M[n2];

	for (int i = 0; i < n1; i++)
		L[i] = arr[p + i];
	for (int j = 0; j < n2; j++)
		M[j] = arr[q + 1 + j];

	// Maintain current index of sub-arrays and main array
	int i, j, k;
	i = 0;
	j = 0;
	k = p;

	// Until we reach either end of either L or M, pick larger among
	// elements L and M and place them in the correct position at A[p..r]
	while (i < n1 && j < n2)
	{
		if (L[i] <= M[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = M[j];
			j++;
		}
		k++;
	}

	// When we run out of elements in either L or M,
	// pick up the remaining elements and put in A[p..r]
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = M[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int a, int b)
{
	if (a < b)
	{
		int mid = (a + b) / 2;
		mergeSort(arr, a, mid);
		mergeSort(arr, mid + 1, b);
		merge(arr, a, mid, b);
	}
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main(int argc, char *argv[])
{
	int n;
	printf("Enter : ");
	scanf("%d", &n);
	int arr[n];
	for (int I = 0; I < n; I++)
	{
		printf(">>");
		cin >> arr[I];
	}
	mergeSort(arr, 0, n);
	printArray(arr, n);
}