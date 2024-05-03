#include <stdio.h>
#include <iostream>
#include <limits>
using namespace std;
int main(int argc, char *argv[])
{
	int n;
	printf("ENTER : ");
	scanf("%d", &n);
	
	int m;
	printf("ENTER : ");
	scanf("%d", &m);
	
	int arr1[n];
	int arr2[m];
	int arr3[12000] = {0};
	int c=0;
	for (int j = 0; j < n; j++)
	{
		printf("%d>>", j + 1);
		cin >> arr1[j];
	}
	for (int j = 0; j < m; j++)
	{
		printf("%d>>", j + 1);
		cin >> arr2[j];
	}


	for (int j = 0; j <n; j++)
	{
		if( arr3[arr1[j]] == 0)
		{
			c++;
		}
		arr3[arr1[j]] = 1;
	}	
	for (int j = 0; j <m; j++)
	{
		if( arr3[arr2[j]] == 0)
		{
			c++;
		}
		arr3[arr2[j]] = 1;
	}
	cout << c;

	return 0;
}
	