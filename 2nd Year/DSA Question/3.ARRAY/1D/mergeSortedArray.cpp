#include <stdio.h>
#include <iostream>
#include <limits>
using namespace std;
void merge(int arr1[], int arr2[],int arr3[], int n1, int n2)
{
    int i = 0, j = 0, k = 0;
    while (i<n1 && j <n2)
    { 
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }
    while (i < n1)
        arr3[k++] = arr1[i++];
    while (j < n2)
        arr3[k++] = arr2[j++];
}
int main(int argc, char *argv[])
{
	int n, m;
	printf("ENTER N: ");
	scanf("%d", &n);
	printf("ENTER M: ");
	scanf("%d", &m);
	int arr1[n], arr2[m] ,arr3[m+n];
	printf("Array 1\n");
	for (int j = 0; j < n; j++)
	{
		printf("%d>>", j + 1);
		cin >> arr1[j];
	}
	printf("Array 2\n");
	for (int j = 0; j < m; j++)
	{
		printf("%d>>", j + 1);
		cin >> arr2[j];
	}
	merge(arr1,arr2,arr3,n,m);
	for (int j = 0; j <(m+n); j++)
	{
		cout<<arr3[j]<<" ";
	}
	return 0;
}