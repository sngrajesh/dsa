// https://leetcode.com/problems/maximum-height-by-stacking-cuboids/

class Solution {
public:
    bool check(vector<int>& a, vector<int>& b) {
        if (b[0] <= a[0] && b[1] <= a[1] && b[2] <= a[2])
            return true;
        else
            return false;
    }

    int
    solveSpaceOptimizedLongestIncreasingSubSequence(int n,
                                                    vector<vector<int>>& a) {
        vector<int> next(n + 1, 0);
        vector<int> curr(n + 1, 0);

        for (int index = n - 1; index >= 0; index--) {
            for (int prevMini = index - 1; prevMini >= -1; prevMini--) {
                int include = 0;
                if (prevMini == -1 || check(a[index], a[prevMini])) {
                    include = a[index][2] + next[index + 1];
                }
                int exclude = next[prevMini + 1];
                curr[prevMini + 1] = max(include, exclude);
            }
            next = curr;
        }
        return next[0];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        // Step 1 : Sort All Dimensions
        for (auto& a : cuboids)
            sort(a.begin(), a.end());

        // Step 2 : Sort All Cuboids on basis on Width or Length
        sort(cuboids.begin(), cuboids.end());

        // Step 3 : Use logic of Longes Increasing Subsequence Lec-119
        return solveSpaceOptimizedLongestIncreasingSubSequence(cuboids.size(),
                                                               cuboids);
    }
};
