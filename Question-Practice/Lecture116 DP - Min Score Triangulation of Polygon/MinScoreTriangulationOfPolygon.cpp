// https://leetcode.com/problems/minimum-score-triangulation-of-polygon/

class Solution {
public:
    int solveRecurssion(vector<int>& val, int i, int j) {
        // base case
        if (i + 1 == j)
            return 0;

        // for choices for k we have use the loop from i+1 to j-1 choices
        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            long long curr = static_cast<long long>(val[i]) * val[k] * val[j] +
                             solveRecurssion(val, i, k) +
                             solveRecurssion(val, k, j);
            ans = min(ans, static_cast<int>(curr));
        }
        return ans;
    }

    int solveMemoization(vector<int>& val, int i, int j,
                         vector<vector<int>>& dp) {
        // base case
        if (i + 1 == j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        // for choices for k we have use the loop from i+1 to j-1 choices
        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            long long curr = static_cast<long long>(val[i]) * val[k] * val[j] +
                             solveMemoization(val, i, k, dp) +
                             solveMemoization(val, k, j, dp);
            ans = min(ans, static_cast<int>(curr));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    int solveTabulation(vector<int>& val) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 2; j<n; j++) {
                int ans = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    int curr = (val[i] * val[k] * val[j]) + dp[i][k] + dp[k][j];
                    ans = min(ans, curr);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][n - 1];
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        /*
        //Recurssion
        return solve(values, 0, n - 1);
        */

        /*
        //Memoization
        vector< vector<int> >dp(n , vector<int>(n , -1));
        return solveMemoization(values, 0, n - 1, dp);
        */

        // Memoization
        return solveTabulation(values);
    }
};
