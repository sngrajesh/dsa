
#include <stdio.h>
#include <iostream>
#include <limits>
using namespace std;

int maxProd1(int arr[], int n)
{
	int max = INT_MIN;
	int j = n - 1;
	for (int a = 0; a < j - 1; a++)
	{
		while (arr[j] < 0)
		{
			j--;
		}
		if (arr[a] < 0)
		{
			int t = arr[a];
			arr[a] = arr[j];
			arr[j] = t;
		}
	}
	for (int a = j - 1; a < n; a++)
	{
		if ((arr[a] > max) && (arr[a] < 0))
		{
			max = arr[a];
		}
	}

	int prod = 1;
	for (int a = 0; a < n; a++)
	{
		if (arr[a] == 0)
			continue;
		prod *= arr[a];
	}
	if ((n - j - 1) % 2 != 0)
	{
		prod /= max;
	}
	return prod;
}

int maxProd2(int arr[], int n)
{
	int prod =1;
	int t =0;
	int max = INT_MIN;
	for (int b = 0; b < n; b++)
	{
		if(arr[b] ==0)
			continue;
		prod *= arr[b];
		if ((arr[b] > max) && (arr[b] < 0))
		{
			max = arr[b];
		}
		if(arr[b] < 0)
		{
			t++;
		}
	}
	
	if(t%2==0)
		return prod;
	else
		return prod/max;	
}

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	int arr[n];
	for (int a = 0; a < n; a++)
		cin >> arr[a];
	cout << endl;
	cout << maxProd1(arr, n) << endl;
	cout << maxProd2(arr, n) << endl;
	return 0;
}

/*

for(int b=0;b<n;b++)
			cout<<arr[b];
		cout<<endl;
		
		
10
1
-2
3
-6
7
-8
-9
3
5
7

*/
