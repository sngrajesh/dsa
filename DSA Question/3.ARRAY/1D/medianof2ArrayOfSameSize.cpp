// Given an array arr[] of N integers, calculate the median
// Expected Time Complexity: O(n * log(n))
// Expected Space Complexity: O(1)
 
/*

Input: N = 5
arr[] = 90 100 78 89 67
Output: 89
Explanation: After sorting the array 
middle element is the median 

Input: N = 4
arr[] = 56 67 30 79 61
Output: 61
Explanation: In case of even number of 
elemebts average of two middle elements 
is the median

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	public:
		int find_median(vector<int> a)
		{
            int n = a.size();
             // If size of the arr[] is even
            if (n % 2 == 0) {
  
                // Applying nth_element/ on n/2th index
                nth_element(a.begin(),a.begin() + n / 2,a.end());
  
                // Applying nth_element on (n-1)/2 th index
                nth_element(a.begin(),a.begin() + (n - 1) / 2,a.end());
  
                // Find the average of value at index N/2 and (N-1)/2
                return (double)(a[(n - 1) / 2] + a[n / 2])/ 2.0;
            }
  
            // If size of the arr[] is odd
            else {
  
                // Applying nth_element on n/2
                nth_element(a.begin(),a.begin() + n / 2,a.end());
  
                // Value at index (N/2)th is the median
                return (double)a[n / 2];
            }
	    }
};

int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(n);
    	for(int i = 0; i < n; i++)
    		cin>>v[i];
    	Solution ob;
    	int ans = ob.find_median(v);
    	cout << ans <<"\n";
    }
	return 0;
}
/*
//Using quick sort method
#include "bits/stdc++.h"
using namespace std;
 
// Utility function to swapping of element
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
// Returns the correct position of pivot element
int Partition(int arr[], int l, int r)
{
    int lst = arr[r], i = l, j = l;
    while (j < r) {
        if (arr[j] < lst) {
            swap(&arr[i], &arr[j]);
            i++;
        }
        j++;
    }
    swap(&arr[i], &arr[r]);
    return i;
}
 
// Picks a random pivot element between l and r and partitions arr[l..r] around the randomly picked element using partition()
int randomPartition(int arr[], int l,
                    int r)
{
    int n = r - l + 1;
    int pivot = rand() % n;
    swap(&arr[l + pivot], &arr[r]);
    return Partition(arr, l, r);
}
 
// Utility function to find median
void MedianUtil(int arr[], int l, int r,
                int k, int& a, int& b)
{
 
    // if l < r
    if (l <= r) {
 
        // Find the partition index
        int partitionIndex
            = randomPartition(arr, l, r);
 
        // If partition index = k, then we found the median of odd number element in arr[]
        if (partitionIndex == k) {
            b = arr[partitionIndex];
            if (a != -1)
                return;
        }
 
        // If index = k - 1, then we get a & b as middle element of arr[]
        else if (partitionIndex == k - 1) {
            a = arr[partitionIndex];
            if (b != -1)
                return;
        }
 
        // If partitionIndex >= k then find the index in first half of the arr[]
        if (partitionIndex >= k)
            return MedianUtil(arr, l,
                              partitionIndex - 1,
                              k, a, b);
 
        // If partitionIndex <= k then find the index in second half of the arr[]
        else
            return MedianUtil(arr,
                              partitionIndex + 1,
                              r, k, a, b);
    }
 
    return;
}
 
// Function to find Median
void findMedian(int arr[], int n)
{
    int ans, a = -1, b = -1;
 
    // If n is odd
    if (n % 2 == 1) {
        MedianUtil(arr, 0, n - 1,
                   n / 2, a, b);
        ans = b;
    }
 
    // If n is even
    else {
        MedianUtil(arr, 0, n - 1,
                   n / 2, a, b);
        ans = (a + b) / 2;
    }
 
    // Print the Median of arr[]
    cout << "Median = " << ans;
}
 
// Driver program to test above methods
int main()
{
    int arr[] = { 12, 3, 5, 7, 4, 19, 26 };
    int n = sizeof(arr) / sizeof(arr[0]);
    findMedian(arr, n);
    return 0;
}
*/