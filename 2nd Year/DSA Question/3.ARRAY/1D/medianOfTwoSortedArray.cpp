/*
Given two sorted arrays, a[] and b[],
the task is to find the median of these sorted arrays, 
in O(log n + log m) time complexity, 
when n is the number of elements in the first array, 
and m is the number of elements in the second array.


Input: ar1[] = {-5, 3, 6, 12, 15}
        ar2[] = {-12, -10, -6, -3, 4, 10}
Output : The median is 3.
Explanation : The merged array is :
        ar3[] = {-12, -10, -6, -5 , -3,
                 3, 4, 6, 10, 12, 15},
       So the median of the merged array is 3


Input: ar1[] = {2, 3, 5, 8}
        ar2[] = {10, 12, 14, 16, 18, 20}
Output : The median is 11.
Explanation : The merged array is :
        ar3[] = {2, 3, 5, 8, 10, 12, 14, 16, 18, 20}
        if the number of the elements are even, 
        so there are two middle elements,
        take the average between the two :
        (10 + 12) / 2 = 11.
*/
/********************************************************************/
/*******************************************************************/
/*******************************************************************/

#include <bits/stdc++.h>
using namespace std; 

int getMedian(int ar1[], int ar2[], int n, int m) 
{ 
    int i = 0; /* Current index of input array ar1[] */
    int j = 0; /* Current index of input array ar2[] */
    int count; 
    int m1 = -1, m2 = -1; 
  
    // Since there are (n+m) elements, 
    // There are following two cases 
    // if n+m is odd then the middle 
    //index is median i.e. (m+n)/2 
    if((m + n) % 2 == 1) 
    { 
        for (count = 0; count <= (n + m)/2; count++)
        { 
            if(i != n && j != m)
            { 
                m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++]; 
            } 
            else if(i < n)
            { 
                m1 = ar1[i++]; 
            } 
            // for case when j<m, 
            else
            { 
                m1 = ar2[j++]; 
            } 
        } 
        return m1; 
    } 
      
    // median will be average of elements 
    // at index ((m+n)/2 - 1) and (m+n)/2 
    // in the array obtained after merging ar1 and ar2 
    else 
    { 
        for (count = 0; count <= (n + m)/2; count++) 
        { 
            m2 = m1; 
            if(i != n && j != m)
            { 
                m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++]; 
            } 
            else if(i < n)
            { 
                m1 = ar1[i++]; 
            } 
            // for case when j<m, 
            else
            { 
                m1 = ar2[j++]; 
            } 
        } 
        return (m1 + m2)/2; 
    } 
} 
/*******************************************************************/
/*******************************************************************/
/*******************************************************************/

 
// A utility function to find median of two integers
float MO2(int a, int b){
     return ( a + b ) / 2.0; 
     }
  
// A utility function to find median of three integers
float MO3(int a, int b, int c){
    return a + b + c - max(a, max(b, c))
                     - min(a, min(b, c));
}
  
// A utility function to find a median of four integers
float MO4(int a, int b, int c, int d){
    int Max = max( a, max( b, max( c, d ) ) );
    int Min = min( a, min( b, min( c, d ) ) );
    return ( a + b + c + d - Max - Min ) / 2.0;
}
  
// Utility function to find median of single array
float medianSingle(int arr[], int n){
   if (n == 0)
      return -1;
   if (n%2 == 0)
        return (double)(arr[n/2] + arr[n/2-1])/2;
   return arr[n/2];
}
  
// This function assumes that N is smaller than or equal to M
// This function returns -1 if both arrays are empty
float findMedianUtil( int A[], int N, int B[], int M ){
    // If smaller array is empty, return median from second array
    if (N == 0)
      return medianSingle(B, M);
  
    // If the smaller array has only one element
    if (N == 1)
    {
        // Case 1: If the larger array also has one element,
        // simply call MO2()
        if (M == 1)
            return MO2(A[0], B[0]);
  
        // Case 2: If the larger array has odd number of elements,
        // then consider the middle 3 elements of larger array and
        // the only element of smaller array. Take few examples
        // like following
        // A = {9}, B[] = {5, 8, 10, 20, 30} and
        // A[] = {1}, B[] = {5, 8, 10, 20, 30}
        if (M & 1)
            return MO2( B[M/2], MO3(A[0], B[M/2 - 1], B[M/2 + 1]) );
  
        // Case 3: If the larger array has even number of element,
        // then median will be one of the following 3 elements
        // ... The middle two elements of larger array
        // ... The only element of smaller array
        return MO3( B[M/2], B[M/2 - 1], A[0] );
    }
  
    // If the smaller array has two elements
    else if (N == 2)
    {
        // Case 4: If the larger array also has two elements,
        // simply call MO4()
        if (M == 2)
            return MO4(A[0], A[1], B[0], B[1]);
  
        // Case 5: If the larger array has odd number of elements,
        // then median will be one of the following 3 elements
        // 1. Middle element of larger array
        // 2. Max of first element of smaller array and element
        //    just before the middle in bigger array
        // 3. Min of second element of smaller array and element
        //    just after the middle in bigger array
        if (M & 1)
            return MO3 ( B[M/2],
                         max(A[0], B[M/2 - 1]),
                         min(A[1], B[M/2 + 1])
                       );
  
        // Case 6: If the larger array has even number of elements,
        // then median will be one of the following 4 elements
        // 1) & 2) The middle two elements of larger array
        // 3) Max of first element of smaller array and element
        //    just before the first middle element in bigger array
        // 4. Min of second element of smaller array and element
        //    just after the second middle in bigger array
        return MO4 ( B[M/2],
                     B[M/2 - 1],
                     max( A[0], B[M/2 - 2] ),
                     min( A[1], B[M/2 + 1] )
                   );
    }
  
    int idxA = ( N - 1 ) / 2;
    int idxB = ( M - 1 ) / 2;
  
     /* if A[idxA] <= B[idxB], then median must exist in
        A[idxA....] and B[....idxB] */
    if (A[idxA] <= B[idxB] )
      return findMedianUtil(A + idxA, N/2 + 1, B, M - idxA );
  
    /* if A[idxA] > B[idxB], then median must exist in
       A[...idxA] and B[idxB....] */
    return findMedianUtil(A, N/2 + 1, B + idxA, M - idxA );
}
  
// A wrapper function around findMedianUtil(). This function
// makes sure that smaller array is passed as first argument
// to findMedianUtil
float findMedian( int A[], int N, int B[], int M ){
    if (N > M)
       return findMedianUtil( B, M, A, N );
  
    return findMedianUtil( A, N, B, M );
}
/****************************************************************/
/****************************************************************/
/****************************************************************/

int main(){

    int arr1[] = {-5, 3, 6, 12, 15};
    int arr2[] = {-12, -10, -6, -3, 4, 10};
    int n1 = sizeof(arr1) / sizeof(arr1[0]); 
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    

    int arr3[] = {2, 3, 5, 8};
    int arr4[] = {10, 12, 14, 16, 18, 20};
    n1 = sizeof(arr3) / sizeof(arr3[0]); 
    n2 = sizeof(arr4) / sizeof(arr4[0]);

    return 0;
}