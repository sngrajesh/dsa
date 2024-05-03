#include <stdio.h>
#include <iostream>
#include <climits>
using namespace std;
int main(int argc, char *argv[])
{
	int n;
	int m = INT_MIN; 
	printf("ENTER : ");
	scanf("%d", &n);

	int arr[n];
	for (int j = 0; j < n; j++)
	{
		printf("%d>>", j + 1);
		cin >> arr[j];
		if (arr[j] > m)
		{
			m = arr[j];
		}
	}

	int arr2[10000] = {0};
	for (int j = 0; j <n; j++)
	{
		arr2[arr[j]] = 1;
	}
	while (1)
	{
		int k;
		printf("\nEnter the value : ");
		scanf("%d", &k);
		int a = 0;
		for (int j = 0; j <m+10; j++)
		{
			if (a == k)
			{
				cout << j-1;
				break;
			}
			if (arr2[j] == 1)
			{
				a++;
			}
		}
	}

	return 0;
}