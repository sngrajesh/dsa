#include <stdio.h>
#include <iostream>
#include <limits>
using namespace std;
void moveNegative (int arr[],int n)
{
	int a=0;
	for(int j=0;j<n;j++)
	{
		if(arr[j] < 0)
		{
			int t =arr[j];
			arr[j] = arr[a];
			arr[a] = t;
			a++;
		}
	}
	
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
	
	moveNegative (arr,n);
	for (int j = 0; j < n; j++)
	{
		cout << arr[j]<<" ";
	}
	return 0;
}