
#include <stdio.h>
#include <iostream>
#include <limits>
using namespace std;

int buy(int arr[] , int n)
{
	int a;
	int r=0;
	int m=0;
	for(a=1 ; a<n ; a++)
	{		
		if((arr[a]-arr[a-1])>=m  &&  arr[a]>arr[a-1])
		{
			m = arr[a]-arr[a-1];
			r=a;
		}
		
	}
	
	return r;
}

int main(int argc, char *argv[])
{
	
	int n;
	printf("ENTER : ");
	scanf("%d", &n);
	int arr[n];
	for (int j = 0; j < n; j++)
	{
		printf("%d>>", j + 1);
		cin >> arr[j];
	}	
	cout<< "\n"<<buy(arr,n);
	
	return 0;
}