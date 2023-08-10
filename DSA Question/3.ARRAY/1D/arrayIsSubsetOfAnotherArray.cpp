#include <set>
#include<unordered_set>
#include<map>
#include <iostream>
using namespace std;


	
bool isSubset1(int arr1[], int arr2[],int m, int n)
{ 
	if (n>m)
		return false;

    // Using STL set for hashing
    set<int> hashset;
 
    // hset stores all the values of arr1
    for (int i = 0; i < m; i++)
    {
        hashset.insert(arr1[i]);
    }
 
    // loop to check if all elements of arr2 also lies in arr1

    for (int i = 0; i < n; i++) {
        if (hashset.find(arr2[i]) == hashset.end())
            return false;
    }
    return true;
}
 
//O(m+n)
bool isSubset2(int arr1[], int arr2[],int m, int n)
{ 
	if (n>m)
		return false;

	unordered_set<int> s;

    for (int i = 0; i < m; i++) 
    {
        s.insert(arr1[i]);
    }

    int p = s.size();
    
    for (int i = 0; i < n; i++) 
    {
        s.insert(arr2[i]);
    }

    if (s.size() == p) {
       return true;
    }
    else {
        return false;
    }

}

bool isSubset3(int arr1[], int arr2[], int m,int n)
{
    if (n>m)
		return false;
		
    // Create a Frequency Table using STL
    map<int, int> frequency;
    
    // Increase the frequency of each element in the frequency table.

    for (int i = 0; i < m; i++)
    {
        frequency[arr1[i]]++;
    }

    // Decrease the frequency if the element was found in the frequency  table with the frequency more than 0. else return 0 and if loop is  completed return 1.
    
    for (int i = 0; i < n; i++) 
    {
        if (frequency[arr2[i]] > 0)
            frequency[arr2[i]]--;
        else
        {
            return false;
        }
    }
    return true;
}

//O(n²)
bool isSubset4(int arr1[], int arr2[], int m, int n)
{
	if (n>m)
		return false;
	int i = 0;
	int j = 0;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (arr2[i] == arr1[j])
				break;
		}
		//If the above inner loop was not broken at all then arr2[i]  is not present in arr1[]
		if (j == m)
			return 0;
	}

	// If we reach here then all elements of arr2[] are present in arr1[]

	return 1;
}


//O(mLogm + nLogn)
bool isSubset5(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
    if (m < n)
        return 0;
    // Sort both the arrays
    sort(arr1, arr1 + m);
    sort(arr2, arr2 + n);
    // Iterate till they donot exceed their sizes
    while (i < n && j < m) 
    {
        // If the element is smaller than Move aheaad in the first array
        if (arr1[j] < arr2[i])
            j++;
        // If both are equal, then move  both of them forward
        else if (arr1[j] == arr2[i]) 
        {
            j++;
            i++;
        } 
        // If we donot have a element smaller or equal to the second array then break
        else if (arr1[j] > arr2[i])
            return 0;
    }
    return (i < n) ? false : true;
}

//O(mlog(m))
void quickSort(int *arr, int si, int ei);
int binarySearch(int arr[], int low, int high, int x);

//Return 1 if arr2[] is a subset of arr1[]
bool isSubset6(int arr1[], int arr2[], int m, int n)
{
	if (n>m)
		return false;
		
	int i = 0;
	quickSort(arr1, 0, m - 1);
	for (i = 0; i < n; i++)
	{
		if (binarySearch(arr1, 0, m - 1,arr2[i])== -1)
			return 0;
	}
	// If we reach here then all elements of arr2[] are present in arr1[] 
	
	return 1;
}

//FOLLOWING FUNCTIONS ARE ONLY FOR SEARCHING AND SORTING PURPOSE 
/* Standard Binary Search function*/

int binarySearch(int arr[], int low, int high, int x)
{
	if (high >= low)
	{
		//low + (high - low)/2;
		int mid = (low + high) / 2;
		/* Check if arr[mid] is the first 
        occurrence of x. arr[mid] is first 
        occurrence if x is one of the following
        is true:
        (i) mid == 0 and arr[mid] == x
        (ii) arr[mid-1] < x and arr[mid] == x    */

		if ((mid == 0|| x>arr[mid-1]) && (arr[mid] == x))
			return mid;
		else if (x > arr[mid])
			return binarySearch(arr, (mid + 1), high, x);
		else
			return binarySearch(arr, low, (mid - 1), x);
	}
	return -1;
}

void exchange(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int A[], int si, int ei)
{
	int x = A[ei];
	int i = (si - 1);
	int j;
	for (j = si; j <= ei - 1; j++)
	{
		if (A[j] <= x)
		{
			i++;
			exchange(&A[i], &A[j]);
		}
	}
	exchange(&A[i + 1], &A[ei]);
	return (i + 1);
}

/* Implementation of Quick Sort
A[] --> Array to be sorted
si --> Starting index
ei --> Ending index
*/

void quickSort(int A[], int si, int ei)
{
	 //Partitioning index
	int pi;

	if (si < ei)
	{
		pi = partition(A, si, ei);
		quickSort(A, si, pi - 1);
		quickSort(A, pi + 1, ei);
	}
}


int main(int argc, char *argv[])
{
	/*
	int n;
	printf("ENTER N : ");
	scanf("%d", &n);
	int arr1[n];
	for (int j = 0; j < n; j++)
	{
		printf("%d>>", j + 1);
		cin >> arr1[j];
	}	
	int m;
	printf("ENTER M : ");
	scanf("%d", &m);
	int arr2[m];
	for (int j = 0; j < m; j++)
	{
		printf("%d>>", j + 1);
		cin >> arr2[j];
	}	
	*/
	int arr1[] = {11, 1, 13, 21, 3, 7};
	int m = sizeof(arr1) / sizeof(arr1[0]);
	int arr2[] = {11, 3, 7, 1};
	int n = sizeof(arr2) / sizeof(arr2[0]);

	if (isSubset5(arr1, arr2, m, n))
		cout << "arr2[] is a subset of arr1[]";
	else
		cout << "arr2[] is not a subset of arr1[]";

	return 0;
}