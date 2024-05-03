#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

// Partitioning routine of Quicksort
int partition(int A[], int n)
{
    int j = 0;
    int pivot = 0;    // consider 0 as a pivot
 
    // each time we find a negative number, `j` is incremented,
    // and a negative element would be placed before the pivot
    for (int i = 0; i < n; i++)
    {
        if (A[i] < pivot)
        {
            swap(A[i], A[j]);
            j++;
        }
    }
 
    // holds the index of the first positive element
    return j;
}
 
// Function to rearrange a given array such that it contains positive
// and negative numbers at alternate positions
void rearrange(int A[], int size)
{
    // partition a given array such that all positive elements move
    // to the end of the array
    int p = partition(A, size);
 
    // swap alternate negative elements from the next available positive
    // element till the end of the array is reached, or all negative or
    // positive elements are exhausted.
 
    for (int n = 0; (p < size && n < p); p++, n += 2) {
        swap(A[n], A[p]);
    }
}
 
void alternateArray(int A[], int n)
{
	int i = 0;
	int j = n - 1;
	while (i <= j)
	{
		if (A[i] < 0 and A[j] > 0)
		{
			int t = A[i];
			A[i] = A[j];
			A[j] = t;
			i++;
			j--;
		}
		else if (A[i] > 0 and A[j] < 0)
		{
			i++;
			j--;
		}
		else if (A[i] > 0)
		{
			i++;
		}
		else if (A[j] < 0)
		{
			j--;
		}

		if (i == 0 or i == (n - 1))
		{
			return;
		}
		else
		{
			int k = 0;
			while (k < n and i < n)
			{
				int t = A[i];
				A[i] = A[k];
				A[k] = t;
				i++;
				k += 2;
			}
		}
	}
}

int main(int argc, char *argv[])
{
	int n1;
	printf("ENTER N1 : ");
	scanf("%d", &n1);
	int A[n1];
	for (int j = 0; j < n1; j++)
	{
		printf("%d>>", j + 1);
		cin >> A[j];
	}

	alternateArray(A, n1);

	for (int j = 0; j < n1; j++)
	{
		cout << A[j] << " ";
	}
	return 0;
}



/*  C++ program to rearrang positive and negative integers in alternate fashion while keeping the order of positive and negative numbers. */
/*
#include <assert.h>
#include <iostream>
using namespace std;
 
// Utility function to right rotate all elements between
// [outofplace, cur]
void rightrotate(int arr[], int n, int outofplace, int cur)
{
    char tmp = arr[cur];
    for (int i = cur; i > outofplace; i--)
        arr[i] = arr[i - 1];
    arr[outofplace] = tmp;
}
 
void rearrange(int arr[], int n)
{
    int outofplace = -1;
 
    for (int index = 0; index < n; index++)
    {
        if (outofplace >= 0)
        {
            // find the item which must be moved into the
            // out-of-place entry if out-of-place entry is
            // positive and current entry is negative OR if
            // out-of-place entry is negative and current
            // entry is negative then right rotate
            //
            // [...-3, -4, -5, 6...] -->   [...6, -3, -4,
            // -5...]
            //      ^                          ^
            //      |                          |
            //     outofplace      -->      outofplace
            //
            if (((arr[index] >= 0) && (arr[outofplace] < 0))
                || ((arr[index] < 0)
                    && (arr[outofplace] >= 0)))
            {
                rightrotate(arr, n, outofplace, index);
 
                // the new out-of-place entry is now 2 steps
                // ahead
                if (index - outofplace >= 2)
                    outofplace = outofplace + 2;
                else
                    outofplace = -1;
            }
        }
 
        // if no entry has been flagged out-of-place
        if (outofplace == -1) {
            // check if current entry is out-of-place
            if (((arr[index] >= 0) && (!(index & 0x01)))
                || ((arr[index] < 0) && (index & 0x01))) {
                outofplace = index;
            }
        }
    }
}
 
// A utility function to print an array 'arr[]' of size 'n'
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
// Driver code
int main()
{
     
    int arr[] = { -5, -2, 5, 2,
                 4, 7, 1, 8, 0, -8 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Given array is \n";
    printArray(arr, n);
 
    rearrange(arr, n);
 
    cout << "Rearranged array is \n";
    printArray(arr, n);
 
    return 0;
}*/
