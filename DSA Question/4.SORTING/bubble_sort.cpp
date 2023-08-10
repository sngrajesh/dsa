#include<stdio.h>
#include<conio.h>
#include<iostream> 
using namespace std;
void swap(int *xp, int *yp) 
{
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}

void bubble_sort(int arr[], int n) 
{ 

    int i, j; 
    for (i = 0; i < n-1; i++) 
	    for (j = 0; j < n-i-1; j++) 
	        if (arr[j] > arr[j+1]) 
	            swap(&arr[j], &arr[j+1]); 
} 

int main(int argc, char *argv[])
{
	int n;
	scanf ("%d",&n);
	int arr[n];
	for(int I = 0 ; I < n ; I++)
	{
		cin>>arr[I];
	}
	bubble_sort(arr,n);
	for(int I = 0 ; I < n ; I++)
	{
		cout<<arr[I];
	}
	
	return 0;
}