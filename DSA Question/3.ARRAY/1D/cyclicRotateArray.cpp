#include <stdio.h>
#include <iostream>
#include <limits>
using namespace std;

void cyclicRotate(int arr[],int n)
{
	int t = arr[0];
	for(int j =0 ; j< (n-1) ;j++)
	{
		arr [j] = arr[j+1];		
	}
	arr[n-1] = t;
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
	
	cyclicRotate(arr,n);
	
	for (int j = 0; j < n; j++)
	{
		
		cout << arr[j];
	}
	return 0;
}