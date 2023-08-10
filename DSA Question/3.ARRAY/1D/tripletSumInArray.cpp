#include <unordered_set>
#include <algorithm>
#include <iostream>
#include<stdio.h>

//Triplet Sum in Array 
using namespace std;

//O(n²)
/*        I----------------------------->I 
		   ↓            					  ↓
arr = [ 0 ; 1 ; 2 ; 3 ; 4 ; 5 ; 6 ; 7 ; 8 ; 9 ]
	            ↑								   ↑
	        	L								   R
*/
bool tripletSum1(int A[], int arr_size, int sum){
	   int l, r;
    /* Sort the elements */
    sort(A, A + arr_size);
    /* Now fix the first element one by one and find the other two elements */
    
    for (int i = 0; i < arr_size - 2; i++) {
        // To find the other two elements, start two index variables from two corners of the array and move them toward each other
        l = i + 1; // index of the first element in the remaining elements
        r = arr_size - 1; // index of the last element
        while (l < r) {
            if (A[i] + A[l] + A[r] == sum) {
                printf("Triplet %d, %d, %d", A[i],A[l], A[r]);
                cout<<endl;
                return true;              
            }
            else if (A[i] + A[l] + A[r] < sum)
                l++;
            else // A[i] + A[l] + A[r] > sum
                r--;
        }
    } 
    // If we reach here, then no triplet was found
    return false;
}


//O(n²)
/*        I--------------------------------->I 
		   ↓      						    	 ↓
arr = [ 0 ; 1 ; 2 ; 3 ; 4 ; 5 ; 6 ; 7 ; 8 ; 9 ; 10 ]
	            ↑											   ↑
	            J--------------------------------------->J
*/
bool tripletSum2(int A[], int arr_size , int sum ){
	// Fix the first element as A[i]
    for (int i = 0; i < arr_size - 2; i++) 
    {
        // Find pair in subarray A[i+1..n-1] with sum equal to sum - A[i]
        unordered_set<int> s;
        int cs = sum - A[i];
        for (int j = i + 1; j < arr_size; j++) 
        {
            if (s.find(cs - A[j]) != s.end()) 
            {
                printf("Triplet %d, %d, %d",A[i],A[j],cs-A[j]);
                cout<<endl;
                return true;
            }
            s.insert(A[j]);
        }
    }
    // If we reach here, then no triplet was found
    return false;
}




int main(int argc, char *argv[])
{
	//n = 6, X = 13
	int arr1[] = {1, 4, 45 ,6 ,10 ,8};
	tripletSum1(arr1,6,13);

	//n = 5, X = 10
	int arr2[] = {1 ,2 ,4 ,3 ,6};
	tripletSum2(arr2,5,10);
	
	return 0;
}