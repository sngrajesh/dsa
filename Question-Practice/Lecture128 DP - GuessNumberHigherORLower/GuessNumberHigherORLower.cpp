// https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/

class Solution {
public:
    int solveRecursssion(int start, int end) {
        if (start >= end)
            return 0;
        int maxi = INT_MAX;

        for (int i = start; i <= end; i++)
            maxi = min(maxi, i + max(solveRecursssion(start, i - 1),
                                     solveRecursssion(i + 1, end)));

        return maxi;
    }

    int solveMemoization(int start, int end, vector<vector<int>>& dp) {
        if (start >= end)
            return 0;
        if (dp[start][end] != -1)
            return dp[start][end];

        int maxi = INT_MAX;

        for (int i = start; i <= end; i++)
            maxi = min(maxi, i + max(solveMemoization(start, i - 1, dp),
                                     solveMemoization(i + 1, end, dp)));

        return dp[start][end] = maxi;
    }

    int solveTabulation(int n) {
        vector<vector<int> > dp(n + 2, vector<int>(n + 2, 0));

        for (int start = n; start >= 1; start--) {
            for (int end = start; end <= n; end++) {
                if (start == end){
                    continue;
                }
                else{
                    int maxi = INT_MAX;
                    for (int i = start; i <= end; i++){
                        maxi = min(maxi, i + max(dp[start][i - 1], dp[i + 1][end]));
                    } 
                    dp[start][end] = maxi;
                }           
            }
        }

        return dp[1][n];
    }

    int getMoneyAmount(int n) {
        // Recurssion
        // return solveRecursssion(0, n);

        // Memoization
        // vector<vector<int> >dp(n+1, vector<int>(n+1,-1));
        // return solveMemoization(0,n,dp);

        // Tabulation
        return solveTabulation(n);
    }
};
