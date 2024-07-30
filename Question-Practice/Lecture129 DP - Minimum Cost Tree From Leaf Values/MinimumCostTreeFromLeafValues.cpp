// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/

class Solution {
public:
    /************************************* Recurssion *************************************/
    int solveRecurssionHelper(int left, int right, vector<int>& arr,
                              map<pair<int, int>, int>& maxi) {

        if (left == right)
            return 0;

        int ans = INT_MAX;

        for (int i = left; i < right; i++) {
            ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] +
                               solveRecurssionHelper(left, i, arr, maxi) +
                               solveRecurssionHelper(i + 1, right, arr, maxi));
        }

        return ans;
    }

    int solveRecurssion(vector<int>& arr, map<pair<int, int>, int>& maxi) {
        return solveRecurssionHelper(0, arr.size() - 1, arr, maxi);
    }

    /************************************* Memoization *************************************/
    int solveMemoizationHelper(int left, int right, vector<int>& arr,
                               map<pair<int, int>, int>& maxi,
                               vector<vector<int>>& dp) {

        if (left == right)
            return 0;

        if (dp[left][right] != -1)
            return dp[left][right];

        int ans = INT_MAX;

        for (int i = left; i < right; i++) {
            ans = min(ans,
                      maxi[{left, i}] * maxi[{i + 1, right}] +
                          solveMemoizationHelper(left, i, arr, maxi, dp) +
                          solveMemoizationHelper(i + 1, right, arr, maxi, dp));
        }

        return dp[left][right] = ans;
    }

    int solveMemoization(vector<int>& arr, map<pair<int, int>, int>& maxi) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solveMemoizationHelper(0, n - 1, arr, maxi, dp);
    }

    /************************************* Tabulation *************************************/

    int solveTabulation(vector<int>& arr, map<pair<int, int>, int>& maxi) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int left = n; left >= 0; left--) {
            for (int right = left; right <= n; right++) {

                if (left == right)
                    continue;

                else {
                    int ans = INT_MAX;

                    for (int k = left; k < right; k++) {
                        ans = min(ans, maxi[{left, k}] * maxi[{k + 1, right}] +
                                           dp[left][k] + dp[k + 1][right]);
                    }

                    dp[left][right] = ans;
                }
            }
        }

        return dp[0][n - 1];
    }

    /************************************* Main Function ************************************/

    int mctFromLeafValues(vector<int>& arr) {

        int n = arr.size();
        map<pair<int, int>, int> maxi;
        for (int i = 0; i < n; i++) {
            maxi[{i, i}] = arr[i];
            for (int j = i + 1; j < n; j++) {
                maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
            }
        }

        // Recurssion
        // return solveRecurssion(arr, maxi);

        // Memoization
        // return solveMemoization(arr, maxi);
        // Tabulation
        return solveTabulation(arr, maxi);
    }
};
