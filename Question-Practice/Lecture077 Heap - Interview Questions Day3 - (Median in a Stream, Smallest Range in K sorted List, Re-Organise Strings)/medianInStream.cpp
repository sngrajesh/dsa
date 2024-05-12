// https://www.naukri.com/code360/problems/median-in-a-stream_975268

/*

	Time complexity: O(N*(log(N))) 
	Space complexity: O(N)
	
	where N is the total number of elements in the array.

*/
#include <bits/stdc++.h>

int signum(int a, int b) {
  if (a == b)
    return 0;
  else if (a > b)
    return 1;
  else
    return -1;
}

void mideanFast(int element, priority_queue<int> &maxHeap,
                priority_queue<int, vector<int>, greater<int>> &minHeap,
                int &median) {
  switch (signum(maxHeap.size(), minHeap.size())) {
  case 0: //maxHeap.size() == minHeap.size()
    if (element > median) {
      // Right Part 
      minHeap.push(element);
      median = minHeap.top();
    } else {
      // Left Part
      maxHeap.push(element);
      median = maxHeap.top();
    }
    break;
  case 1: //maxHeap.size() > minHeap.size()
    if (element > median) {
      minHeap.push(element);
      median = (maxHeap.top() + minHeap.top()) / 2;
    } else {
		minHeap.push(maxHeap.top());
		maxHeap.pop();
		maxHeap.push(element);
		median = (maxHeap.top() + minHeap.top()) / 2;
    }
    break;
  case -1: //maxHeap.size() < minHeap.size()
    if (element > median) {
			maxHeap.push(minHeap.top());
			minHeap.pop();
			minHeap.push(element);
			median = (maxHeap.top() + minHeap.top()) / 2;
    } else {
		maxHeap.push(element);
		median = (maxHeap.top() + minHeap.top()) / 2;
    }
    break;
  }
}

vector<int> findMedian(vector<int> &arr, int n) {

  int median = -1;
  vector<int> ans;
  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;

  for (int i = 0; i < n; i++) {
    mideanFast(arr[i], maxHeap, minHeap, median);
    ans.push_back(median);
  }

  return ans;
}

/************************************************* Brute force approach **********************************************************/
/*

	Time complexity: O(N*(N*log(N))) 
	Space complexity: O(N)
	
	where N is the total number of elements in the array.

*/

#include <algorithm>

vector<int> findMedianBruteForce(vector<int> &arr, int n){
	
	// To store the incoming stream elements
	vector<int>store;
	
	// To store the medians
	vector<int> medians;
	
	for(int i = 0; i < n; i++){
		
		// Storing the incoming data from stream in a vector 'store'
		store.push_back(arr[i]);
		
		// Sorting the vector to arrange all the elements in sorted order
		sort(store.begin(),store.end());
		
		int median;
		// Even number of elements are read, (Note - 0 based indexing is used)
		if((i+1)%2==0){
			
			// Average of middle two values
			median = (store[i/2] + store[(i+1)/2])/2;
				
		}
		// odd number of elements are read
		else{
			
			// The middle value of the sorted arrangement of the elements read so far
			median = store[i/2];
			
		}
		
		medians.push_back(median);
		
	}
	
	return medians;
}


/************************************************* Insertion Sort **********************************************************/
/*

	Time complexity: O(N*N) 
	Space complexity: O(N)
	
	where N is the total number of elements in the array.

*/

vector<int> findMedianInsertionSort(vector<int> &arr, int n){
	
	//To store the incoming elements
	vector<int> store;
	
	// To store the medians
	vector<int> medians;
	
	for(int i = 0; i < n; i++){
		
		// Insert the new element in the store vector 
		store.push_back(arr[i]);
		
		// shift it at its sorted position in store
		int j = 0;
		
		while(j < i){
			
			if(store[j] <= arr[i]){
				j++;	
			}
			else{
				break;
			}
			
		}
		
		// Shifting all the elements greater than the current element to the right 
		
		int k = i-1;
		
		while(k >= j){
			
			store[k+1] = store[k];
			k--;
			
		}
		
		// Inserting the current element at its sorted position
		store[j] = arr[i];
			
		int median;
		// Even number of elements are read, (Note - 0 based indexing is used)
		if((i+1)%2==0){
			
			// Average of middle two values
			median = (store[i/2] + store[(i+1)/2])/2;
				
		}
		// odd number of elements are read
		else{
			
			// The middle value of the sorted arrangement of the elements read so far
			median = store[i/2];
			
		}
		
		medians.push_back(median);
				
	}
	
	return medians;
}


