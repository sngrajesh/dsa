// https://www.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1


//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    /****************************** Brute Force *****************************/
    int helperSBT(int A[], int index, int diff){
        if(index < 0) 
            return 0;
            
        int ans = 0;
        for(int i = index-1; i >= 0; i--)
            if(A[index]- A[i] == diff) 
                ans = max(ans , 1 + helperSBT(A, i,  diff));

        return ans;
    }
    
    int solveBruteForce(int A[], int n){
        if(n <= 2) return n;
        int ans = 0;
        
        for(int i = 0; i <n ; i++){
            for(int j = i+1; j < n; j++){
                ans = max(ans, 2 + helperSBT(A, i, A[j]- A[i]));
            }
        }
        return ans;
    }
    
    /****************************** Memoization *****************************/    
    int helperMemoization(int A[], int index, int diff, vector<unordered_map<int, int> > &dp){
        if(index < 0) 
            return 0;
            
        if(dp[index][diff]) return dp[index][diff];
        
        int ans = 0;
        for(int i = index-1; i >= 0; i--)
            if(A[index]- A[i] == diff) 
                ans = max(ans , 1 + helperSBT(A, i,  diff));

        return dp[index][diff] = ans;
    }
    
    int solveMemoization(int A[], int n){
        if(n <= 2) return n;
        vector<unordered_map<int, int> > dp(n+1);
        
        int ans = 0;
        for(int i = 0; i <n ; i++){
            for(int j = i+1; j < n; j++){
                ans = max(ans, 2 + helperMemoization(A, i, A[j]- A[i], dp));
            }
        }
        return ans;
    }
    
    /****************************** Tabulation *****************************/    
    int solveTabulation(int A[], int n) {
        if (n <= 2) return n;
        
        int ans = 2; // Since the minimum length of AP can be 2.
        unordered_map<int, int> dp[n+1];
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) { // Corrected inner loop condition
                int diff = A[i] - A[j];
                int cnt = 1;
                
                if (dp[j].count(diff)) {
                    cnt = dp[j][diff];
                }
                
                dp[i][diff] = 1 + cnt;
                ans = max(ans, dp[i][diff]);
            }
        }
        
        return ans;
    }
    
    int lengthOfLongestAP(int A[], int n) {
        // return solveBruteForce(A,n);
        // return solveMemoization(A,n);
        return solveTabulation(A,n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
