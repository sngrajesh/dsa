// SuperSetOfSubSet.cpp
// https://leetcode.com/problems/subsets/submissions/1177026797/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void subsetsSolution(vector<vector<int>> &ans, vector<int> nums, vector<int> output, int i)
    {
        if (i >= nums.size())
        {
            ans.push_back(output);
            return;
        }
        subsetsSolution(ans, nums, output, i + 1);
        output.push_back(nums[i]);
        subsetsSolution(ans, nums, output, i + 1);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> output;
        subsetsSolution(ans, nums, output, 0);
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    vector<int> num{1, 2, 3};
    Solution a;
    vector<vector<int>> ans = a.subsets(num);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[" ;
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "]" <<endl;
    }
    cout << endl;

    return 0;
}