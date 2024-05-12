https://www.naukri.com/code360/problems/k-th-largest-sum-contiguous-subarray_920398
#include <queue>
#include <algorithm>

//Method 1 : By Using Array and Sorting
int getKthLargest(vector<int> &arr, int k) {
  vector<int> largesrArray;

  for (int i = 0; i < arr.size(); i++) {
    int sum = 0;
    for (int j = i; j < arr.size(); j++) {
      sum += arr[j];
      largesrArray.push_back(sum);
    }
  }

  sort(largesrArray.begin(), largesrArray.end());
 
  return largesrArray[largesrArray.size() - k];
}




// Methoda 2
// Optimize size of Array from O(n^2) to O(K)
int getKthLargest(vector<int> &arr, int k) {
  priority_queue<int, vector<int>, greater<int>> q;

  for (int i = 0; i < arr.size(); i++) {
    int sum = 0;
    for (int j = i; j < arr.size(); j++) {
      sum += arr[j];
      if (q.size() < k) {
        q.push(sum);
      } else {
        if (sum > q.top()) {
          q.pop();
          q.push(sum);
        }
      }
    }
  }
  return q.top();
}
