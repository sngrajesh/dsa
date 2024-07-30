// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee

class Solution {
public:
    int solveRecurssion(int index, int buy, int fee, vector<int>& prices) {
        if (index == prices.size())
            return 0;

        int profit = 0;
        if (buy) {
            int buyIt = -prices[index] + solveRecurssion(index + 1, 0,fee, prices);
            int skipIt = 0 + solveRecurssion(index + 1, 1,fee, prices);
            profit = max(buyIt, skipIt);
        } else {
            int sellIt = prices[index] + solveRecurssion(index + 1, 1, fee, prices) - fee;
            int skipIt = 0 + solveRecurssion(index + 1, 0, fee, prices);
            profit = max(sellIt, skipIt);
        }

        return profit;
    }

    int solveMemoization(int index, int buy, int fee, vector<int>& prices, vector<vector<int>>& dp) {
        if (index == prices.size())
            return 0;
        if (dp[index][buy] != -1)
            return dp[index][buy];

        int profit = 0;
        if (buy) {
            int buyIt = -prices[index] + solveMemoization(index + 1, 0, fee, prices, dp);
            int skipIt = 0 + solveMemoization(index + 1, 1, fee, prices, dp);
            profit = max(buyIt, skipIt);
        } else {
            int sellIt = prices[index] + solveMemoization(index + 1, 1, fee, prices, dp) - fee;
            int skipIt = 0 + solveMemoization(index + 1, 0, fee, prices, dp);
            profit = max(sellIt, skipIt);
        }

        return dp[index][buy] = profit;
    }

    int solveTabulation(int fee, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        int ans = 0;
        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 1; buy >= 0; buy--) {
                int profit = 0;
                if (buy) {
                    int buyIt = -prices[index] + dp[index + 1][0];
                    int skipIt = 0 + dp[index + 1][1];
                    profit = max(buyIt, skipIt);
                } else {
                    int sellIt = prices[index] + dp[index + 1][1] - fee;
                    int skipIt = 0 + dp[index + 1][0];
                    profit = max(sellIt, skipIt);
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }

    int solveSpaceOptimized(int fee, vector<int>& prices) {
        int n = prices.size();
        vector<int>curr(2, 0);
        vector<int>next(2, 0);
        int ans = 0;
        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 1; buy >= 0; buy--) {
                int profit = 0;
                if (buy) {
                    int buyIt = -prices[index] + next[0];
                    int skipIt = 0 + next[1];
                    profit = max(buyIt, skipIt);
                } else {
                    int sellIt = prices[index] + next[1] - fee;
                    int skipIt = 0 + next[0];
                    profit = max(sellIt, skipIt);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return next[1];
    }

    int maxProfit(vector<int>& prices, int fee) {
        // Recurssion
        // return solveRecurssion(0, 1,fee, prices);

        // Memoization
        // int n = prices.size();
        // vector<vector<int>> dp(n+1, vector<int>(2, -1));
        // return solveMemoization(0, true, fee, prices, dp);

        // Tabulation
        // return solveTabulation(fee, prices);

        // Space Optimized
        return solveSpaceOptimized(fee, prices);
  
    }
};
