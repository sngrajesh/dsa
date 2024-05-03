// https://www.naukri.com/code360/problems/smallest-range-from-k-sorted-list_1069356

#include <bits/stdc++.h>

class Node {
public:
  int data;
  int row;
  int col;

  Node(int data, int row, int col) {
    this->data = data;
    this->row = row;
    this->col = col;
  }
};

class Compare {
  public:
  bool operator()(Node *a, Node *b) { return a->data > b->data; }
};

int kSorted1(vector<vector<int>> &a, int k, int n) {

  priority_queue<Node * , vector<Node*>, Compare> pq;

  int mini = INT_MAX;
  int maxi = INT_MIN;
  for (int i = 0; i < k; i++) {
    pq.push(new Node(a[i][0], i, 0));
    mini = min(mini, a[i][0]);
    maxi = max(maxi, a[i][0]);
  }

  int start = mini;
  int end = maxi;

  while (!pq.empty()) {
    Node *temp = pq.top();
    pq.pop();

    mini = temp->data;

    if (maxi - mini < end - start) {
      start = mini;
      end = maxi;
    }

    if (temp->col +1 < n) {
      maxi = max(maxi, a[temp->row][temp->col + 1]);
      pq.push(new Node(a[temp->row][temp->col + 1], temp->row, temp->col + 1));
    } else {
      break;
    }
  }
    return end - start + 1;
}


/********************************************************************************************************/
// Brute Force
/*
	Time Complexity: O(N^3 * K^3)
	Space complexity: O(N*K)

	Where ‘N’ is the number of elements present in each list and ‘K’ is the number of lists.

*/
 
// This function will return true if given start end include at least element from each list
bool validRange(vector<vector<int>> &a, int start, int end, int k, int n) {
    for (int i = 0; i < k; ++i) {
        bool found = false;
        for (int j = 0; j < n; ++j) {
            // Check if any element lie in our current range
            if (start <= a[i][j] && a[i][j] <= end) {
                found = true;
                break;
            }
        }
        // If we can not find any elements which lie in our range then we return false
        if (!found) {
            return false;
        }
    }
    // If for each element in the list we always find some element which lie in our range then we return true
    return true;
}

int kSorted2(vector<vector<int>> &a, int k, int n) {
    vector<int> list;
    // Storing all the elements in 1D list
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            list.push_back(a[i][j]);
        }
    }
    sort(list.begin(), list.end());
    int ans = INT_MAX;
    // Check for all possible range
    for (int i = 0; i < list.size(); ++i) {
        for (int j = i; j < list.size(); ++j) {
            int start = list[i];
            int end = list[j];
            // If current range is valid then compare its len with minimum length
            if (validRange(a, start, end, k, n)) {
                int len = end - start + 1;
                ans = min(ans, len);
            }
        }
    }

    return ans;
}



/********************************************************************************************************/
// Greedy Approach using Pointers Technique


/*
	Time Complexity: O(N * K^2)
	Space complexity: O(K)

	Where ‘N’ is the number of elements present in each list and ‘K’ is the number of lists.

*/


int kSorted3(vector<vector<int>> &a, int k, int n) {
    // Definition: index[i] will store the index of next element that we will consider from the ith list
    vector<int> index(k, 0);
    int ans = INT_MAX;
    // It will store the index of the list that contain the minimum element among the elements we consider
    int minIdx = 0;

    // We search our answer till one of the list exhausted
    while (index[minIdx] < n) {
        int minn = INT_MAX, maxx = INT_MIN;
        // We find minimum and maximum element that we will be our starting and ending of the range
        for (int i = 0; i < k; ++i) {
            if (minn > a[i][index[i]]) {
                minn = a[i][index[i]];
                minIdx = i;
            }
            if (maxx < a[i][index[i]]) {
                maxx = a[i][index[i]];
            }
        }
        int len = maxx - minn + 1;
        // Update the answer with new range
        ans = min(ans, len);
        // Increment the index of minimum element
        index[minIdx]++;
    }

    return ans;
}

