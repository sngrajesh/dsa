
// https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/
class Solution {
public:
    int solveRecurssion(vector<int>& nums1, vector<int>& nums2, int index,
                        bool swapped) {
        if (index >= nums1.size())
            return 0;

        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        if (swapped)
            swap(prev1, prev2);

        int ans = INT_MAX;

        // Not sawapped
        if (prev1 < nums1[index] && prev2 < nums2[index])
            ans = min(ans, solveRecurssion(nums1, nums2, index + 1, 0));

        // Swapped
        if (prev1 < nums2[index] && prev2 < nums1[index])
            ans = min(ans, 1 + solveRecurssion(nums1, nums2, index + 1, 1));

        return ans;
    }

    int solveMemoization(vector<int>& nums1, vector<int>& nums2, int index,
                         bool swapped, vector<vector<int>>& dp) {
        if (index >= nums1.size())
            return 0;
        if (dp[index][swapped] != -1)
            return dp[index][swapped];

        int ans = INT_MAX;
        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        if (swapped)
            swap(prev1, prev2);


        // Not sawapped
        if (prev1 < nums1[index] && prev2 < nums2[index])
            ans = min(ans, solveMemoization(nums1, nums2, index + 1, 0, dp));

        // Swapped
        if (prev1 < nums2[index] && prev2 < nums1[index])
            ans =
                min(ans, 1 + solveMemoization(nums1, nums2, index + 1, 1, dp));

        return dp[index][swapped] = ans;
    }

    int solveTabulation(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for (int index = n - 1; index >= 1; index--) {
            for (int swapped = 1; swapped >= 0; swapped--) {
                int ans = INT_MAX;
                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                if (swapped)
                    swap(prev1, prev2);

                // Not sawapped
                if (prev1 < nums1[index] && prev2 < nums2[index])
                    ans = min(ans,dp[index + 1][0]);

                // Swapped
                if (prev1 < nums2[index] && prev2 < nums1[index])
                    ans = min(ans, 1 + dp[index + 1][1]);

                dp[index][swapped] = ans;
            }
        }

        return dp[1][0];
    }

    int solveSpaceOptimization(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int>current(2, 0);
        vector<int>next(2, 0);

        for (int index = n - 1; index >= 1; index--) {
            for (int swapped = 1; swapped >= 0; swapped--) {
                int ans = INT_MAX;
                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                if (swapped)
                    swap(prev1, prev2);

                // Not sawapped
                if (prev1 < nums1[index] && prev2 < nums2[index])
                    ans = min(ans,next[0]);

                // Swapped
                if (prev1 < nums2[index] && prev2 < nums1[index])
                    ans = min(ans, 1 + next[1]);

                current[swapped] = ans;
            }
            next = current;
        }

        return next[0];
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        int n = nums1.size();

        /*
        // Recurssion
        return solveRecurssion(nums1, nums2, 1, 0);
        */

        /*
        // Meoization
        vector<vector<int> >dp(n+1, vector<int>(2,-1));
        return solveMemoization(nums1, nums2, 1, 0, dp);
        */

        /*
        return solveTabulation(nums1, nums2);
        */

        return solveSpaceOptimization(nums1, nums2);
    }
};
