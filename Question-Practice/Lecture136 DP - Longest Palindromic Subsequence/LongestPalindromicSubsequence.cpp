// https://leetcode.com/problems/longest-palindromic-subsequence/

#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int solveRecursion(string text1, string text2, int i, int j) {
        if (i >= text1.size() || j >= text2.size())
            return 0;

        if (text1[i] == text2[j]) {
            return 1 + solveRecursion(text1, text2, i + 1, j + 1);
        } else {
            return max(solveRecursion(text1, text2, i + 1, j),
                       solveRecursion(text1, text2, i, j + 1));
        }
    }

    int solveMemoization(string& text1, string& text2, int i, int j,
                         vector<vector<int>>& dp) {
        if (i >= text1.size() || j >= text2.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (text1[i] == text2[j]) {
            dp[i][j] = 1 + solveMemoization(text1, text2, i + 1, j + 1, dp);
        } else {
            dp[i][j] = max(solveMemoization(text1, text2, i + 1, j, dp),
                           solveMemoization(text1, text2, i, j + 1, dp));
        }
        return dp[i][j];
    }

    int solveTabulation(string text1, string text2) {
        int n = text1.size(); 
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[0][0];
    }


    int solveSpaceOptimized(string text1, string text2) {
        int n = text1.size(); 
        vector<int>curr(n+1, 0);
        vector<int>next(n+1, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    curr[j] = 1 + next[j + 1];
                } else {
                    curr[j] = max(next[j], curr[j + 1]);
                }
            }
            next = curr;
        }
        return next[0];
    }


    int longestPalindromeSubseq(string s) {
        string r = s; 
        reverse(r.begin(), r.end()); 

        // Recursion
        // return solveRecursion(s, r, 0, 0);

        // Memoization
        // int n = s.size(); 
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solveMemoization(s, r, 0, 0, dp);

        // Tabulation
        // return solveTabulation(s, r);

        // Space Optimized
        return solveSpaceOptimized(s, r);

    }
};

