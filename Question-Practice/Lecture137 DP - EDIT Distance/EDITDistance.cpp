// https://leetcode.com/problems/edit-distance/

class Solution {
public:
    int solveRecurssion(string word1, string word2,int i, int j){
        if(i == word1.length())
            return word2.length() - j;
        
        if(j == word2.length())
            return word1.length() - i;

        int ans = 0;

        if(word1[i] == word2[j]){
            ans =  solveRecurssion(word1, word2, i+1,j+1);
        } else { 
            int ins = 1 +  solveRecurssion(word1, word2, i,j+1);
            int del = 1 +  solveRecurssion(word1, word2, i+1,j);
            int repl = 1 + solveRecurssion(word1, word2, i+1,j+1);
            
            ans = min(ins, min(del,repl)); 
        }
        
        return ans;
    }
    
    int solveMemoization(string word1, string word2,int i, int j, vector<vector<int>> &dp){
        if(i == word1.length())
            return word2.length() - j;
        
        if(j == word2.length())
            return word1.length() - i;

        if(dp[i][j] != -1) 
            return dp[i][j]; 

        int ans = 0;

        if(word1[i] == word2[j]){
            ans =  solveMemoization(word1, word2, i+1,j+1, dp);
        } else { 
            int ins = 1 +  solveMemoization(word1, word2, i,j+1, dp);
            int del = 1 +  solveMemoization(word1, word2, i+1,j, dp);
            int repl = 1 + solveMemoization(word1, word2, i+1,j+1, dp);
            
            ans = min(ins, min(del,repl)); 
        }
        
        return dp[i][j] = ans;
    }

    int solveTabulation(string word1, string word2){
        
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for(int j = 0; j < m; j++)
            dp[n][j] = word2.length() - j;
        for(int i = 0; i < n; i++)
            dp[i][m] = word1.length() - i;

        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                int ans = 0;
                if(word1[i] == word2[j]){
                    ans =  dp[i+1][j+1];
                } else { 
                    int ins = 1 +  dp[i][j+1];
                    int del = 1 +  dp[i+1][j];
                    int repl = 1 + dp[i+1][j+1];
                    
                    ans = min(ins, min(del,repl)); 
                }
                dp[i][j] = ans;
            }
        }    

        return dp[0][0];
    }

    int solveSpaceOptimized(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int> curr(m + 1, 0);
        vector<int> next(m + 1, 0);
         
        for (int j = 0; j <= m; j++)
            next[j] = m - j;
        
        for (int i = n - 1; i >= 0; i--) {
            curr[m] = n - i; // Initialize the last element of the current row
            
            for (int j = m - 1; j >= 0; j--) {
                int ans = 0;
                if (word1[i] == word2[j]) {
                    ans = next[j + 1];
                } else {
                    int ins = 1 + curr[j + 1];
                    int del = 1 + next[j];
                    int repl = 1 + next[j + 1];
                    
                    ans = min(ins, min(del, repl));
                }
                curr[j] = ans;
            }
            next = curr;
        }
        
        return next[0];
    }


    int minDistance(string word1, string word2) {
        // Recurssion
        // return solveRecurssion(word1, word2, 0, 0);

        // Memoization
        // int n = word1.length();
        // int m = word2.length();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solveMemoization(word1, word2, 0, 0, dp);

        // Tabulation
        // return solveTabulation(word1, word2);

        // Space Optimied
        return solveSpaceOptimized(word1, word2);
 
    }
};
