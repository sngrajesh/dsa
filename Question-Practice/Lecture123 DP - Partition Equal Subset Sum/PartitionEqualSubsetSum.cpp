// https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int solveRecurssion(int index,int arr[],int N, int target){
        if(index >= N) return 0;
        if(target < 0 ) return 0;
        if(target == 0) return 1;
        
        int include = solveRecurssion(index+1, arr, N, target - arr[index]);
        int exclude = solveRecurssion(index+1, arr, N, target);
        
        return include || exclude;
    }
    
    int solveMemoization(int index,int arr[],int N, int target, vector<vector<int> >&dp){
        if(index >= N) return 0;
        if(target < 0 ) return 0;
        if(target == 0) return 1;
        
        if(dp[index][target] != -1) return dp[index][target];
        
        int include = solveRecurssion(index+1, arr, N, target - arr[index]);
        int exclude = solveRecurssion(index+1, arr, N, target);
        
        dp[index][target] = include || exclude;
        return dp[index][target];
    }
    
    
    int solveTabulation(int arr[],int N, int total){
        
        vector<vector<int> >dp(N + 1, vector<int>(total + 1 , 0));
        for(int i = 0; i <= N; i++) dp[i][0] = 1;
        
        for(int index = N - 1; index >= 0; index--){
            for(int target = 0; target <= total/2; target ++){
                int include = 0;
                if(target - arr[index] >= 0)
                    include = dp[index+1][target - arr[index]];
                int exclude = dp[index+1][target];
                
                dp[index][target] = include || exclude;
            }
        }
        return dp[0][total/2];
    }
    
    int solveSpaceOptimization(int arr[],int N, int total){
        
        vector<int>current(total + 1 , 0);
        vector<int>next(total + 1 , 0);
        next[0] = 1;
        current[0] = 1;
        
        for(int index = N - 1; index >= 0; index--){
            for(int target = 0; target <= total/2; target ++){
                int include = 0;
                if(target - arr[index] >= 0)
                    include = next[target - arr[index]];
                int exclude = next[target];
                current[target] = include || exclude;
            }
            next = current;
        }
        return next[total/2];
    }
    
    
    int equalPartition(int N, int arr[])
    {   int target = 0;
        for(int i = 0; i < N; i++) 
            target+= arr[i];
            
        if(target & 1) return 0; // Odd Number not possible to obtainn 2x sum
        /*
        //Recurssion
        // return  solveRecurssion(0, arr, N, target / 2);
        */
        
        /*
        // Memoization
        vector<vector<int> >dp(N, vector<int>(target , -1));
        return solveMemoization(0, arr, N, target / 2, dp);
        */
        
        // Tabulation
        return solveSpaceOptimization(arr, N, target);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends
