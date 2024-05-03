#include <iostream>
#include <algorithm>
using namespace std;

/* ALGORITHM 1	time-O(n²).  space-O(1)
a=0
a=a+(min(left, right)-arr[i])

i  |		3	0	0	2	0	4
---|-------------------------------------------------
0 |		l=3	r=4	a=0+3-3 = 0
1 |		l=3	r=4	a=0+3-0 = 3
2 |		l=3	r=4	a=3+3-0 = 6
3 |		l=3	r=4	a=6+3-2 = 7
4 |		l=3	r=4	a=7+3-0 = 10

*/
int trappingRainWater1(int arr[], int n){
	// To store the maximum water that can be stored
    int res = 0;
    // For every element of the array find 
    for (int i = 1; i < n-1; i++) {       
               
    // Find the maximum element on its left
         int left = arr[i];
        for (int j=0; j<i; j++)
           left = max(left, arr[j]);

	// Find the maximum element on its left
        int right = arr[i];
        for (int j=i+1; j<n; j++)
           right = max(right, arr[j]); 
           
       // Update the maximum water    
       res = res + (min(left, right) - arr[i]);   
    }
    return res; 
}







/* ALGORITHM 2 	time-O(n).  space-O(n)
a=0
a=a+min(left[i], right[i]) - arr[i];

i		][		3	0	0	2	0	4
--------][-------------------------------------------------
Larr ][		3	3	3	3	3	4
Rarr ][		4	4	4	4	4	4
--------][-------------------------------------------------
0 	  ][		l=3	r=4	a=0+3-3   = 0
1 	  ][		l=3	r=4	a=0+3-0   = 3
2	   ][		l=3	r=4	a=3+3-0   = 6
3 	  ][		l=3	r=4	a=6+3-2   = 7
4	   ][		l=3	r=4	a=7+3-0   = 10
5	   ][		l=4	r=4	a=10+4-4 = 10		
*/
int trappingRainWater2(int arr[], int n)
{
    // left[i] contains height of tallest bar to the left of i'th bar including itself
    int left[n];
    
    // Right [i] contains height of tallest bar to the right of ith bar including itself
    int right[n];
 

    // Initialize result
    int water = 0;
 
    // Fill left array
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], arr[i]);
 
    // Fill right array
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], arr[i]);
 
    // Calculate the accumulated water element by element, consider the amount of water on i'th bar, the amount of water accumulated on this particular bar will be equal to min(left[i], right[i]) - arr[i] .

    for (int i = 0; i < n; i++)
        water += min(left[i], right[i]) - arr[i];
    return water;
}








/*ALGORITHM 3	time-O(n).  space-O(1)*/
int trappingRainWater3(int arr[], int n)
{
    // initialize output
    int result = 0; 

    // maximum element on left and right
    int left_max = 0, right_max = 0;
 
    // indices to traverse the array
    int lo = 0, hi = n - 1;

    while (lo <= hi) {
        if (arr[lo] < arr[hi]) {
            if (arr[lo] > left_max)
                // update max in left
                left_max = arr[lo];
            else
	// water on curr element = max - curr
                result += left_max - arr[lo];
            lo++;
        }
        else {
            if (arr[hi] > right_max)
			    // update right maximum
                right_max = arr[hi];
            else
                result += right_max - arr[hi];
            hi--;
        }
    }
    return result;
}












/*ALGORITHM 4	time-O(n).  space-O(1)*/int trappingRainWater4(int arr[], int n)
{

    int size = n - 1;
    //Let the first element be stored as previous, we shall loop from index 1
    int prev = arr[0];
 
    // To store previous wall's index
    int prev_index = 0;
    int water = 0;
 
    // To store the water until a larger wall is found, if there are no larger walls then delete temp value from water
    int temp = 0;

    for(int i = 1; i <= size; i++)
    {
        // If the current wall is taller than the previous wall then make current wall as the previous wall and its index as previous wall's index for the subsequent loops
        if (arr[i] >= prev) 
        {
            prev = arr[i];
            prev_index = i;
            // Because larger or same height wall is found
            temp = 0;
        } 
        else
        {
	// Since current wall is shorter than the previous, we subtract previous wall's height from the current wall's height and add it to the water
            water += prev - arr[i];
 
	//Store the same value in temp as well If we dont find any larger wall then we will subtract temp from water
            temp += prev - arr[i];
        }
    }

    // If the last wall was larger than or equal to the previous wall then prev_index would be equal to size of the array (last element) If we didn't find a wall greater than or equal to the previous wall from the left then prev_index must be less than the index of the last element
    if(prev_index < size) 
    {
        // Temp would've stored the water collected from previous largest wall till the end of array if no larger wall was found then it has excess water and remove that from water variable
        water -= temp; 

        // We start from the end of the array, so previous should be assigned to the last element
        prev = arr[size];

        // Loop from the end of array up to the  previous index which would contain the largest wall from the left
        for(int i = size; i >= prev_index; i--) 
        { 
		//Right end wall will be definitely smaller than the 'previous index' wall

            if(arr[i] >= prev)
            {
                prev = arr[i];
            } 
            else
            {
                water += prev - arr[i];
            }
        }
    }
    // Return the maximum water
    return water;
}












int main(int argc, char *argv[])
{
	int M = 6;
	int arr1[] = {3, 0, 0, 2, 0, 4};
	cout<<trappingRainWater1(arr1,M)<<" ";
	cout<<trappingRainWater2(arr1,M)<<" ";
	cout<<trappingRainWater3(arr1,M)<<" ";
	cout<<trappingRainWater4(arr1,M)<<" ";
	cout<<endl;
	
	int N = 4;
	int arr2[] = {7, 4, 0, 9};
	cout<<trappingRainWater1(arr2, N)<<" ";
	cout<<trappingRainWater2(arr2, N)<<" ";
	cout<<trappingRainWater3(arr2, N)<<" ";
	cout<<trappingRainWater4(arr2, N)<<" ";
	cout<<endl;
	
	int O = 3;
	int arr3[] = {6, 9, 9};
	cout<<trappingRainWater1(arr3,O)<<" ";
	cout<<trappingRainWater2(arr3,O)<<" ";
	cout<<trappingRainWater3(arr3,O)<<" ";
	cout<<trappingRainWater4(arr3,O)<<" ";
	cout<<endl;
	return 0;
}