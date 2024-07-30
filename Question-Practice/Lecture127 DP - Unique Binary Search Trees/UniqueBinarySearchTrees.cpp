// https://leetcode.com/problems/unique-binary-search-trees/submissions/1271791854/
 
 
 class Solution {
public:
    
    int solveRecurssive(int n){
        if(n <= 1) return 1;

        int ans = 0;
        for(int i = 1 ; i <= n; i++){
            ans += solveRecurssive(i-1) * solveRecurssive(n - i);
        }

        return ans;
    }

    int solveMemoization(int n, vector<int>&dp){
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];

        int ans = 0;
        for(int i = 1 ; i <= n; i++){
            ans += solveMemoization(i-1, dp) * solveMemoization(n - i, dp);
        }

        return dp[n] = ans;
    }

    int solveTabulation(int n){
        vector<int>dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++)
            for(int j = 1 ; j <= i; j++)
                dp[i] += dp[j-1] * dp[i - j];       
        return dp[n];
    }

    int solveCatelanNumber(int n){
        long long res = 1;
        for (int i = 1; i <= n; i++) {
            res *= (n+i);
            res /= i;
        }
        return res/(n+1);
    }

    int numTrees(int n) {   
        //Recurssion
        // return solveRecurssive(n);   

        //Memoization
        // vector<int>dp(n+1, -1);
        // return solveMemoization(n, dp); 

        //Tabulation
        // return solveTabulation(n);

        //Catelan Number
        return solveCatelanNumber(n);
    }
}; 
