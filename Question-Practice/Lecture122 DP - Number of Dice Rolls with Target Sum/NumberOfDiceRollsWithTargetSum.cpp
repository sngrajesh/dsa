// https://www.geeksforgeeks.org/problems/dice-throw5349/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long solveRecursion(int dices ,int faces , int target) {
        if(target < 0) return 0;
        if(target == 0 && dices != 0) return 0;
        if(target != 0 && dices == 0) return 0;
        if(target == 0 && dices == 0) return 1;
        
        long long ans = 0;
        for(int i = 1 ; i <= faces; i++)
            ans += solveRecursion(dices - 1, faces, target - i);
            
        return ans;
    }
    
    long long solveMemoization(int dices ,int faces , int target, vector<vector<long long>>& dp) {
        if(target < 0) return 0;
        if(target == 0 && dices != 0) return 0;
        if(target != 0 && dices == 0) return 0;
        if(target == 0 && dices == 0) return 1;
        
        if(dp[dices][target] != -1) return dp[dices][target];
        
        long long ans = 0;
        for(int i = 1 ; i <= faces; i++)
            ans += solveMemoization(dices - 1, faces, target - i, dp);
        dp[dices][target] = ans;
        
        return dp[dices][target];
    }
    
    long long solveTabulation(int N ,int M , int X) {
        vector<vector<long long>> dp(N+1, vector<long long>(X+1, 0));
        dp[0][0] = 1;
            
        for(int dices = 1 ; dices <= N; dices++){
            for(int target = 1; target <= X; target++){
                long long ans = 0;
                for(int i = 1 ; i <= M; i++){
                    if(target - i >= 0){
                        ans += dp[dices - 1][target - i];
                    }
                }
                dp[dices][target] = ans;
            }
        }
        return dp[N][X];
    }
    
    long long solveSpaceOptimization(int N ,int M , int X) {
        vector<long long>current(X+1, 0);
        vector<long long>previous(X+1, 0);
        previous[0] = 1;
        
        for(int dices = 1 ; dices <= N; dices++){
            for(int target = 1; target <= X; target++){
                long long ans = 0;
                for(int i = 1 ; i <= M; i++){
                    if(target - i >= 0){
                        ans += previous[target - i];
                    }
                }
                current[target] = ans;
            }
            previous = current;
        }
        return previous[X];
    }

    long long noOfWays(int M , int N , int X) {
        /*
        // Recursion
        return solveRecursion(N, M, X);
        */
        
        /*
        // Memoization
        vector<vector<long long>> dp(N+1, vector<long long>(X+1, -1));
        return solveMemoization(N, M, X, dp);
        */
        
        /*
        // Tabulation
        return solveTabulation(N, M, X);
        */
        
        // Space Optimized
        return solveSpaceOptimization(N, M, X);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends
