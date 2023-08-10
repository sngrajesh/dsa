#include <stdio.h>
#include <iostream>
#include <limits>

using namespace std;
int kadens(int arr[], int n)
{
	int m = INT32_MIN;
	int cs = 0;
	for (int j = 0; j < n; j++)
	{
		cs += arr[j];
		if (m < cs)
			m = cs;
		if (cs < 0)
			cs = 0;
	}

	return m;
}
int main(int argc, char *argv[])
{
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int j = 0; j < n; j++)
	{
		printf("%d>>", j);
		cin >> arr[j];
	}
	cout << kadens(arr, n) << endl;
	return 0;
}