#include<iostream>
#include <algorithm> 
#include<vector>

using namespace std;

// Test Case
// k=3
// stalls = [10 1 2 7 5]
// ans -> 4 [1 , 5 , 10]

bool isPossible(vector<int> &stalls, int k, int mid, int n) {
    int cowCount = 1;
    int lastPos = stalls[0];
    
    for(int i=0; i<n; i++ ){
        if(stalls[i]-lastPos >= mid){
            cowCount++;
            if(cowCount==k)
            {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    //[1 2 5 7 10]
    int n = stalls.size();
    int ans = -1;

   	int s = 0;
    int e=stalls[n-1];
    int mid = s + (e-s)/2;
    
    
    while(s<=e) {
        if(isPossible(stalls, k, mid, n)) {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

