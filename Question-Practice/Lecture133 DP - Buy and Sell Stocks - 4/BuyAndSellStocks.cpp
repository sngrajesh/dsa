// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
class Solution {
public:
    int solveRecurssion(int index, int buy, int count, vector<int>& prices) {
        if (index == prices.size() || count == 0)
            return 0;

        int profit = 0;
        if (buy) {
            int buyIt =
                -prices[index] + solveRecurssion(index + 1, 0, count, prices);
            int skipIt = 0 + solveRecurssion(index + 1, 1, count, prices);
            profit = max(buyIt, skipIt);
        } else {
            int sellIt = prices[index] +
                         solveRecurssion(index + 1, 1, count - 1, prices);
            int skipIt = 0 + solveRecurssion(index + 1, 0, count, prices);
            profit = max(sellIt, skipIt);
        }
        return profit;
    }

    int solveMemoization(int index, int buy, int count, vector<int>& prices,
                         vector<vector<vector<int>>>& dp) {
        if (index == prices.size() || count == 0)
            return 0;
        if (dp[index][buy][count] != -1)
            return dp[index][buy][count];

        int profit = 0;
        if (buy) {
            int buyIt = -prices[index] +
                        solveMemoization(index + 1, 0, count, prices, dp);
            int skipIt = 0 + solveMemoization(index + 1, 1, count, prices, dp);
            profit = max(buyIt, skipIt);
        } else {
            int sellIt = prices[index] +
                         solveMemoization(index + 1, 1, count - 1, prices, dp);
            int skipIt = 0 + solveMemoization(index + 1, 0, count, prices, dp);
            profit = max(sellIt, skipIt);
        }
        return dp[index][buy][count] = profit;
    }

    int solveTabulation(int k,vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int count = 1; count <= k; count++) {
                    int profit = 0;
                    if (buy) {
                        int buyIt = -prices[index] + dp[index + 1][0][count];
                        int skipIt = 0 + dp[index + 1][1][count];
                        profit = max(buyIt, skipIt);
                    } else {
                        int sellIt =
                            prices[index] + dp[index + 1][1][count - 1];
                        int skipIt = 0 + dp[index + 1][0][count];
                        profit = max(sellIt, skipIt);
                    }
                    dp[index][buy][count] = profit;
                }
            }
        }

        return dp[0][1][k];
    }

    int maxProfit(int k, vector<int>& prices) {
        // Recurssion
        // return solveRecurssion(0, 1, k, prices);

        // Memoization
        // int n = prices.size();
        // vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1))); 
        // return solveMemoization(0, 1, k, prices, dp);

        // Tabulation
        return solveTabulation(k, prices);
      
    }
};
