#include <stdio.h>
#include <iostream>
#include <limits>
using namespace std;

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
	for (int j = 0; j < n; j++)
	{
		if (arr[j] > max)
		{
			max = arr[j];
		}
		if (arr[j < min])
		{
			min = arr[j];
		}
	}
	printf("MAX : %d MIN : %d",max,min);
}