//Chocolate Distribution Problem
/*
n= 8, m = 5;
arr[]= {3, 4, 1, 9, 56, 7, 9, 12};Output: 6
Explanation: The minimum difference between maximum chocolates and minimum chocolates is 9 - 3 = 6 by choosing following M packets : {3, 4, 9, 7, 9}.
*/	

#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

//	0	1	2	3	4	5	6	7	8	9	10
//	^							 ^
//	l							  r
int chockoDay(int n, int m, int arr[]){
	
	// if there are no chocolates or number of students is 0
    if (m == 0 || n == 0)
        return 0;
 

    // Sort the given packets
    sort(arr, arr + n); 

    // Number of students cannot be more than number of packets
    if (n < m)
        return -1; 

    // Largest number of chocolates

    int min_diff = INT_MAX;
 
    // Find the subarray of size m such that difference between last (maximum in case of sorted) and first (minimum in case of sorted) elements of subarray is minimum.
 
    for (int i = 0; i + m - 1 < n; i++) {
        
        int diff = arr[i + m - 1] - arr[i];

        if (diff < min_diff)
            min_diff = diff;
    }

    return min_diff;
}


int main(int argc, char *argv[])
{
	
	int N1 = 17 , M1 = 7;
	int A[] = {12, 4, 7, 9, 2, 23, 25, 41, 30,40, 28, 42, 30, 44, 48, 43, 50} ;		
	cout<< chockoDay(N1, M1, A)<<endl;
	
	int N2 = 7, M2 = 3;
	int B[] = {7, 3, 2, 4, 9, 12, 56};
	cout<< chockoDay(N2, M2, B)<<endl;

	int N3= 8, M3 = 5;
	int C[] = {3, 4, 1, 9, 56, 7, 9, 12};
	cout<< chockoDay(N3, M3, C)<<endl;				
	return 0;
}