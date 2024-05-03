//Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.
#include <algorithm>
#include <iostream>
using namespace std;

void dnfSort_1(int arr[], int n)
{
	int zero = 0;
	int one = 0;
	int two = 0;
	for (int j = 0; j < n; j++)
	{
		if (arr[j] == 0)
			zero++;
		else if (arr[j] == 1)
			one++;
		else if (arr[j] == 2)
			two++;
	}

	int l = 0;
	int u1 = one + two;
	int u2 = one + zero + two;
	for (int j = 0; j < n; j++)
	{
		if (u2 == u1 || u2 == two)
		{
			l++;
		}
		arr[j] = l;
		u2--;
	}

	for (int j = 0; j < n; j++)
	{
		cout << " " << arr[j];
	}
}
void swap (int* a, int* b)
{
	int t= *a;
	*a=*b;
	*b=t;
}

void dnfSort_2(int arr[], int n)
{
	int l = 0, m = 0, h = n - 1;
	while (m <= h)
	{
		if (arr[m] == 0)
		{
			swap(arr[m], arr[l]);
			l++;
			m++;
		}
		else if (arr[m] == 1)
			m++;
		else
			{
				swap(arr[m], arr[h]);
				h--;
			}
	}
	for (int j = 0; j < n; j++)
	{
		cout << " " << arr[j];
	}
}

int main(int argc, char *argv[])
{
	int n;
	printf("ENTER : ");
	cin >> n;
	int arr[n];
	for (int j = 0; j < n; j++)
	{
		printf("%d>>", j + 1);
		cin >> arr[j];
	}
	dnfSort_1(arr, n);
	cout<<endl<<endl;
	dnfSort_2(arr, n);
	return 0;
}