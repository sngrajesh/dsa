// https://leetcode.com/problems/intersection-of-two-arrays/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hashSet(nums1.begin(), nums1.end()); 
        unordered_set<int> result; 

        for (int num : nums2) {
            if (hashSet.count(num)) {
                result.insert(num); 
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};



/*
#include <vector>
using namespace std;
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	int i = 0, j = 0;
    vector<int> ans;
    while(i<n && j<m) {

    if(arr1[i]==arr2[j])
    {
    	ans.push_back(arr1[i]);
        i++;
        j++;
    }
    else if (arr1[i] < arr2[j]) {
  		i++;
    }
    else
    {
    	j++;
    }

    }
    return ans;
}
*/
