// https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261


#include <bits/stdc++.h>
/***************************************** Recurssion **************************************/
int solveRecurssion(vector<int> &nums, int n) {

  if (n < 0) {
    return 0;   
  }

  if (n == 0) {
    return nums[0];
  }
  int inc = solve(nums, n - 2) + nums[n];
  int exc = solve(nums, n - 1) + 0;
  return max(inc, exc);
}

int maximumNonAdjacentSumRecurssion(vector<int> &nums) {
  int n = nums.size();
  if (n == 0) {
    return 0;
  }
  int ans = solve(nums, n);
  return ans;
}
/***************************************** DP - Top Down **************************************/
int solveMemo(vector<int> &nums, int n, vector<int> &dp) {

  if (n < 0)
    return 0;
    
  if (n == 0)
    return nums[0];

  if (dp[n] != -1)
    return dp[n];

  int inc = solveMemo(nums, n - 2, dp) + nums[n];
  int exc = solveMemo(nums, n - 1, dp) + 0;
  dp[n] = max(inc, exc);

  return dp[n];
}

int maximumNonAdjacentSumMemo(vector<int> &nums) {

  int n = nums.size();

  if (n == 0) 
    return 0;
  

  vector<int> dp(n, -1);
  int ans = solveMemo(nums, n - 1, dp);

  return ans;
}
/***************************************** DP - Bottom Up **************************************/
int maximumNonAdjacentSumBottomUp(vector<int> &nums) {
  int n = nums.size();

  if (n == 0)
    return 0;

  vector<int> dp(n, 0);
  dp[0] = nums[0];

  for (int i = 1; i < n; i++) {
    int inc = dp[i - 2] + nums[i];
    int exc = dp[i - 1] + 0;
    dp[i] = max(inc, exc);
  }

  return dp[n - 1];
}
/***************************************** DP - Space Optimize **************************************/
int maximumNonAdjacentSumSpaceOptimize(vector<int> &nums) {
  int n = nums.size();

  if (n == 0)
    return 0;

  int prev2 = 0;
  int prev1 = nums[0];

  for (int i = 1; i < n; i++) {
    int inc = prev2 + nums[i];
    int exc = prev1;

    int ans = max(inc, exc);
    prev2 = prev1;
    prev1 = ans;
  }
  return prev1;
}
















