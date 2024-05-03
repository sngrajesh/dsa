// A C++ program to find if there is a zero subayrray sum

#include <iostream>
#include <map>
using namespace std;

bool subArrayExists(int arr[], int n)
{
	map <int,bool> sumSet;

	// Traverse through array and store prefix sums
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];

		// If prefix sum is 0 or it is already present
		if (sum == 0 || sumSet.count(sum))
			return true;
		else 
			sumSet[sum] = true;
	}
	return false;
}

// Driver code
int main()
{
	int arr[] = {4, 2, -3, 1, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
	if (subArrayExists(arr, n))
		cout << "Found a subarray with 0 sum";
	else
		cout << "No Such Sub Array Exists!";
	return 0;
}
