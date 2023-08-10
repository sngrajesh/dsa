/*Given an array of N integers arr[] where each element represents the max number of steps that can be made forward from that element. Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.*/

#include <algorithm>
#include <iostream>
using namespace std;
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
	if (arr[0] == 0)
		{
			exit(1);
		}

	int nos = 0, k = 1;
	for (int j = 0; j < n; j++)
	{
		k += arr[j];
		nos++;
		if (k>=n)
		{
			break;
		}
	}
	cout << nos;
	return 0;
}
