// https://www.geeksforgeeks.org/problems/get-minimum-squares0538/1

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	
	int solveRecurssion(int n){
	    if(n == 0 ) return 0;
	     
	    int ans = n;
	    for(int i = 1; i*i <= n; i++){
	        ans =  min(ans ,1 +  MinSquares(n - i*i));
	    }
	    return ans;
	}
	
	int solveMemo(int n, vector<int>&dp){
	    if(n == 0 ) return 0;
        if(dp[n] != -1)
            return dp[n] ;
	    
	    int ans = n;
	    for(int i = 1; i*i <= n; i++)
	        ans =  min(ans ,1 +  solveMemo(n - i*i,dp));
	    dp[n]  = ans;
	    return dp[n];
	}
	
	int solveTabulation(int n){
	   vector<int>dp(n+1, INT_MAX);
	    dp[0] = 0;
	    int ans = n;
	    for(int in = 1; in <= n; in++)
    	    for(int j = 1; j*j <= n; j++)
    	        if(in - j*j >= 0)
        	        dp[in] =  min(dp[in] ,1 +  dp[in - j*j]);
	    return dp[n];
	}
	    
	int MinSquares(int n) {
	   //return solveRecurssion(n);
	   
	   //vector<int>dp(n+1,  -1);
	   //return solveMemo(n , dp);
	
	    return solveTabulation(n);
	}
};  

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
