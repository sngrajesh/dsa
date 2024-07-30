// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

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

    int solveTabulation(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int count = 1; count <= 2; count++) {
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

        return dp[0][1][2];
    }

    int solveSpaceOP(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> curr(2, vector<int>(3, 0));
        vector<vector<int>> next(2, vector<int>(3, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int limit = 1; limit <= 2; limit++) {
                    int profit = 0;
                    if (buy) {
                        profit = max((-prices[index] + next[0][limit]),
                                     (0 + next[1][limit]));
                    } else {
                        profit = max((+prices[index] + next[1][limit - 1]),
                                     (0 + next[0][limit]));
                    }
                    curr[buy][limit] = profit;
                }
            }
            next = curr;
        }
        return next[1][2];
    }

    int maxProfit(vector<int>& prices) {
        // Recurssion
        // return solveRecurssion(0, 1, 2, prices);

        // Memoization
        // int n = prices.size();
        // vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2,
        // vector<int>(3, -1))); return solveMemoization(0, 1, 2, prices, dp);

        // Tabulation
        // return solveTabulation(prices);

        // Space Optimized
        return solveSpaceOP(prices);
    }
};
