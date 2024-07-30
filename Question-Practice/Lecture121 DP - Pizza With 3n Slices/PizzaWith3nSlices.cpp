// https://leetcode.com/problems/pizza-with-3n-slices/description/
class Solution {
public:
    int sovleRecurssion(int index, int endIndex, vector<int>& slices, int n) {
        // base case
        if (n == 0 || index > endIndex) {
            return 0;
        }
        int take =
            slices[index] + sovleRecurssion(index + 2, endIndex, slices, n - 1);
        int notTake = 0 + sovleRecurssion(index + 1, endIndex, slices, n);
        return max(take, notTake);
    }

    int sovleMemoization(int index, int endIndex, vector<int>& slices, int n,
                         vector<vector<int>>& dp) {
        // base case
        if (n == 0 || index > endIndex) {
            return 0;
        }

        if (dp[index][n] != -1)
            return dp[index][n];

        int take = slices[index] +
                   sovleMemoization(index + 2, endIndex, slices, n - 1, dp);
        int notTake = 0 + sovleMemoization(index + 1, endIndex, slices, n, dp);

        dp[index][n] = max(take, notTake);
        return dp[index][n];
    }

    int sovleTabulation(vector<int>& slices) {
        int k = slices.size();
        
        vector<vector<int>> dp1(k + 2, vector<int>(k, 0));
        for (int index = k - 2; index >= 0; index--) {
            for (int n = 1; n <= k / 3; n++) {
                int take = slices[index] + dp1[index + 2][n - 1];
                int notTake = 0 + dp1[index + 1][n];
                dp1[index][n] = max(take, notTake);
            }
        }
        int case1 = dp1[0][k / 3];

        vector<vector<int>> dp2(k + 2, vector<int>(k, 0));
        for (int index = k - 1; index >= 1; index--) {
            for (int n = 1; n <= k / 3; n++) {
                int take = slices[index] + dp2[index + 2][n - 1];
                int notTake = 0 + dp2[index + 1][n];
                dp2[index][n] = max(take, notTake);
            }
        }
        int case2 = dp2[1][k / 3];

        return max(case1, case2);
    }

    int sovleSpaceOptimized(vector<int>& slices) {
        int k = slices.size();
        
        vector<int>prev1(k,0);
        vector<int>curr1(k,0);
        vector<int>next1(k,0);
        for (int index = k - 2; index >= 0; index--) {
            for (int n = 1; n <= k / 3; n++) {
                int take = slices[index] + next1[n - 1];
                int notTake = 0 + curr1[n];
                prev1[n] = max(take, notTake);
            }
            next1 = curr1;
            curr1 = prev1;
        }
        int case1 = curr1[k / 3];

        vector<int>prev2(k,0);
        vector<int>curr2(k,0);
        vector<int>next2(k,0);
        vector<vector<int>> dp2(k + 2, vector<int>(k, 0));
        for (int index = k - 1; index >= 1; index--) {
            for (int n = 1; n <= k / 3; n++) {
                int take = slices[index] + next2[n - 1];
                int notTake = 0 + curr2[n];
                prev2[n] = max(take, notTake);
            }
            next2 = curr2;
            curr2 = prev2;
        }
        int case2 = curr2[k / 3];

        return max(case1, case2);
    }


    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();

        /*
        // Recursssion
        int case1 = sovleRecurssion(0, n-2 ,slices, n / 3);
        int case2 = sovleRecurssion(1, n-1 ,slices, n / 3);
        return max(case1, case2);
        */

        /*
        // Memoization
        vector<vector<int> >dp1(n, vector<int>(n, -1));
        int case1 = sovleMemoization(0, n-2 ,slices, n / 3, dp1);
        vector<vector<int> >dp2(n, vector<int>(n, -1));
        int case2 = sovleMemoization(1, n-1 ,slices, n / 3, dp2);
        return max(case1, case2);
        */
        
        /*
        // Tabulation
        return sovleTabulation(slices);
        */

        // Space Optimized
        return sovleSpaceOptimized(slices);

    }
};
