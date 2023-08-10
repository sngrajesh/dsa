#include <conio.h>
#include <iostream>
#include <limits>
using namespace std;

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
 

void selection_sort(int arr[], int n) 
{ 
    int i, j, min_idx;  
    for (i = 0; i < n-1; i++) 
    { 
       min_idx = i; 
        for (j = i+1; j < n; j++) 
        if (arr[j] < arr[min_idx]) 
            min_idx = j;  
        swap(&arr[min_idx], &arr[i]); 

    } 
} 
int main(int argc, char *argv[])
{
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int I = 0; I < n; I++)
	{
		cin >> arr[I];
	}
	selection_sort(arr, n);
	for (int I = 0; I < n; I++)
	{
		cout << arr[I];
	}

	return 0;
}