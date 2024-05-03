// Permutation of Integer Array
// https://leetcode.com/problems/permutations/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    void permuteSolve(vector<int> nums, int i, vector<vector<int>> &ans) {
        if (i >= nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int j = i; j < nums.size(); j++) {
            swap(nums[j], nums[i]);
            permuteSolve(nums, i + 1, ans);
            swap(nums[j], nums[i]);
        }
    }

   public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> ans;
        permuteSolve(nums, 0, ans);
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> nums{1, 2, 3};
    vector<vector<int>> ans = s.permute(nums);

    for (int i = 0; i < ans.size(); i++) {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "]" << endl;
    }
    cout << endl;

    return 0;
}