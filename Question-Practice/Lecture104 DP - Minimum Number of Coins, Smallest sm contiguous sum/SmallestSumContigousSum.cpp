// https://www.geeksforgeeks.org/problems/smallest-sum-contiguous-subarray/1


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int smallestSumSubarray(vector<int>& arr){
    int res = arr[0];
    int minEnding = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        minEnding = min(minEnding + arr[i], arr[i]);
        res = min(res, minEnding);
    }
    return res;
  }
};


//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        
        int ans = ob.smallestSumSubarray(a);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends