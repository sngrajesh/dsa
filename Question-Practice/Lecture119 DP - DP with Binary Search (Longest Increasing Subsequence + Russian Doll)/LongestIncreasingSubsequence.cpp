// https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    
    int solveRecurssion(int n, int a[], int index, int prevMini){
        if(n == index) return 0;
        
        int include = 0;
        if( prevMini == -1 ||  a[prevMini] < a[index]){
            include = 1 + solveRecurssion(n, a, index+1, index);
        }
        int exclude = solveRecurssion(n, a, index+1, prevMini);
        
        return max(include, exclude);
    }
    
    int solveMemoization(int n, int a[], int index, int prevMini, vector<vector<int>> &dp){
        if(n == index) return 0;
        
        if(dp[index][prevMini+1] != -1) // +1 for zero base indexing
            return dp[index][prevMini +1];
        
        int include = 0;
        if( prevMini == -1 ||  a[prevMini] < a[index]){
            include = 1 + solveMemoization(n, a, index+1, index, dp);
        }
        int exclude = solveMemoization(n, a, index+1, prevMini, dp);
        dp[index][prevMini+1] = max(include, exclude);
        
        return dp[index][prevMini + 1];
    }
    
    
    int solveTabulation(int n, int a[]) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    
        for (int index = n - 1; index >= 0; index--) {
            for (int prevMini = index - 1; prevMini >= -1; prevMini--) {
                int include = 0;
                if (prevMini == -1 || a[prevMini] < a[index]) {
                    include = 1 + dp[index + 1][index + 1];
                }
                int exclude = dp[index + 1][prevMini + 1];
                dp[index][prevMini + 1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }

    
    int solveSpaceOptimized(int n, int a[]) {
        vector<int> next(n + 1, 0);
        vector<int> curr(n + 1, 0);
    
        for (int index = n - 1; index >= 0; index--) {
            for (int prevMini = index - 1; prevMini >= -1; prevMini--) {
                int include = 0;
                if (prevMini == -1 || a[prevMini] < a[index]) {
                    include = 1 + next[index + 1];
                }
                int exclude = next[prevMini + 1];
                curr[prevMini + 1] = max(include, exclude);
            }
            next = curr;
        }
        return next[0];
    }
    
    int solveDPWithBinarySearch(int n ,int a[]) {
        if(n==0) return 0;
        
        
        vector<int> ans;
        ans.push_back(a[0]);
        
        for(int i =1; i<n; i++) {
            if(a[i] > ans.back()) {
                ans.push_back(a[i]);
            }
            else {
                //we have to find the just next big index then that
                //lower bound return the address of just big element 
                //Substrcting asn.begin() will give correct  index of that big element 
                int index = lower_bound(ans.begin(),ans.end(), a[i]) - ans.begin();
                ans[index] = a[i];
            }
        }
        return ans.size();
    }

    
    int longestSubsequence(int n, int a[]){
        
        /*
        //Recurssion
        return solveRecurssion(n, a, 0, -1);
        */
        
        /*
        //Memoization
        vector<vector<int> >dp(n +1 , vector<int>(n + 1, -1));
        return solveMemoization(n, a, 0, -1 ,dp);
        */
        
        /*
        //Tabulation
        return solveTabulation(n, a);
        */
        
        /*
        //Space Optmizec
        return solveSpaceOptimized(n, a);
        */
        
        //DP with binary Search
        return solveDPWithBinarySearch(n,a);
        
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends
