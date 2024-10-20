// https://www.naukri.com/code360/problems/minimum-elements_3843091

#include <bits/stdc++.h> 

/***************************************** Recursion ****************************************/
int solveRecurssion(vector<int> &nums, int x){
    if(x == 0) return 0;
    if(x < 0) return INT_MAX;

    int mini =INT_MAX;
    for(auto i : nums){
        int ans = solve(nums , x - i);
        if(ans != INT_MAX) {
            mini = min(mini ,1 + ans);
        }
    }
    return mini;
}

int minimumElementsRecurssion(vector<int> &num, int x){
    int ans =  solve(num, x);
    if(ans == INT_MAX) return -1;
    return ans;
}




/***************************************** DP - Top Down ****************************************/ 
int solveDPTopDown(vector<int> &nums, int x, vector<int>&dp){
    if(x == 0) return 0;
    if(x < 0) return INT_MAX;

    if(dp[x] != -1) return dp[x];

    int mini =INT_MAX;
    for(auto i : nums){
        int ans = solve(nums , x - i ,dp);
        if(ans != INT_MAX) {
            mini = min(mini ,1 + ans);
        }
    }
    dp[x] =  mini;
    return dp[x];
}

int minimumElementsDPTopDown(vector<int> &num, int x){
    vector<int>dp(x+1 , -1);
    int ans =  solve(num, x, dp);
    if(ans == INT_MAX) return -1;
    return ans;
} 

/***************************************** DP - Bottom Up ****************************************/
int minimumElementsDPBottomUp(vector<int> &num, int x) {
  vector<int> dp(x + 1, INT_MAX);
  dp[0] = 0;

  for (int i = 1; i <= x; i++)
    for (int j = 0; j < num.size(); j++)
      if (i - num[j] >= 0 && dp[i - num[j]] != INT_MAX)
        dp[i] = min(dp[i], 1 + dp[i - num[j]]);

  if (dp[x] == INT_MAX)
    return -1;
  return dp[x];
}



 
