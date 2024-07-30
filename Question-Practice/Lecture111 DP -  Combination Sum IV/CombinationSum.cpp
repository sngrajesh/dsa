// https://www.naukri.com/code360/problems/number-of-ways_3755252

#include <bits/stdc++.h>
/************************* Recurssion *************************/ 
int RecSolve(vector<int> &num, int target) {
  if (target < 0)
    return 0;
  if (target == 0)
    return 1;
  int count = 0;
  for (auto val : num)
    count += RecSolve(num, target - val);

  return count;
}

int findWaysRec(vector<int> &num, int tar) { return RecSolve(num, tar); }	

/************************* DP - Top Down *************************/ 
int solveMemo(vector<int> &num, int target, vector<int> &dp) {
  if (target < 0)
    return 0;
  if (target == 0)
    return 1;

  if (dp[target] != -1)
    return dp[target];

  int count = 0;
  for (auto val : num)
    count += solveMemo(num, target - val, dp);

  dp[target] = count;
  return dp[target];
}

int findWaysMemo(vector<int> &num, int tar) {
  vector<int> dp(tar + 1, -1);
  return solve(num, tar, dp);
}

/************************* DP - Bottom Up *************************/ 
int findWaysTab(vector<int> &num, int tar) {
  vector<int> dp(tar + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= tar; i++) {
    for (int j = 0; j < num.size(); j++) {
      if (i - num[j] >= 0) {
        dp[i] += dp[i - num[j]];
      }
    }
  }
  return dp[tar];
}
/************************* DP - Space Optimized *************************/ 
// Not Possible - Same as Tabulation
