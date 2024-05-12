// https://www.naukri.com/code360/problems/0-1-knapsack_920542

#include <bits/stdc++.h>

/************************************** Recurssion ********************************/
int solve(vector<int> &weight, vector<int> &value, int n, int maxWeight) {
  if (n == 0) {
    if (weight[0] <= maxWeight)
      return value[0];
    else
      return 0;
  }

  // Otherwise, return the maximum of two cases:
  // 1. nth item included
  // 2. not included
  int include = 0;
  if(weight[n] <= maxWeight)
     include = value[n] + solve(weight, value, n - 1, maxWeight - weight[n]);

  int exclude = solve(weight, value, n - 1, maxWeight);

  return max(include, exclude);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
  return solve(weight, value, n - 1, maxWeight);
}

/************************************** DP - Top DOwn **********************************/
int solveMem(vector<int> &weight, vector<int> &value, int n, int maxWeight, vector<vector<int> > &dp) {
  
  if (n == 0) {
    if (weight[0] <= maxWeight)
      return value[0];
    else
      return 0;
  }
  if(maxWeight == 0) return 0;

  if (dp[n][maxWeight] != -1)
    return dp[n][maxWeight];

  int include = 0;
  if (weight[n] <= maxWeight)
    include = value[n] + solve(weight, value, n - 1, maxWeight - weight[n], dp);

  int exclude = solve(weight, value, n - 1, maxWeight, dp);

  dp[n][maxWeight]  = max(include, exclude);
  return dp[n][maxWeight];
}

int knapsackMem(vector<int> weight, vector<int> value, int n, int maxWeight) {
  vector<vector<int> > dp(n, vector<int>(maxWeight+1 , -1));
  return solveMem(weight, value, n - 1, maxWeight, dp);
}


/***************************** DP - Bottom Up *******************************/
int knapsackTab(vector<int> &weight, vector<int> &value, int n, int maxWeight){

    vector<vector<int>> dp(n, vector<int> (maxWeight+1, 0));

    for(int w = weight[0];w<=maxWeight; w++){
        if(weight[0] <= maxWeight){
            dp[0][w] = value[0];
        } else{
            dp[0][w] = 0;
        }
    }

    for(int index=1;index<n;index++){
        for(int w = 0;w<=maxWeight; w++){
            int include = 0;
            if(weight[index] <= w){
                include = value[index] + dp[index-1][w - weight[index]];
            }
            int exclude = dp[index-1][w];
            dp[index][w] = max(include, exclude);
        }
    }
    return dp[n-1][maxWeight];
}
/****************************** DP - Space Optimized ****************************/
int knapsackSO(vector<int> &weight, vector<int> &value, int n, int maxWeight) {

  vector<int>prev(maxWeight + 1, 0);
  vector<int>curr(maxWeight + 1, 0);

  for (int w = weight[0]; w <= maxWeight; w++) {
    if (weight[0] <= maxWeight) {
      prev[w] = value[0];
    } else {
      prev[w] = 0;
    }
  }

  for (int index = 1; index < n; index++) {
    for (int w = 0; w <= maxWeight; w++) {
      int include = 0;
      if (weight[index] <= w) {
        include = value[index] + prev[w - weight[index]];
      }
      int exclude = prev[w];
      curr[w] = max(include, exclude);
    }
    prev = curr;
  }
  return prev[maxWeight];
} 


/***************************** DP - Over Optimized *******************************/
int knapsackOOpti(vector<int> &weight, vector<int> &value, int n, int maxWeight) {

  vector<int>curr(maxWeight + 1, 0);

  for (int w = weight[0]; w <= maxWeight; w++) {
    if (weight[0] <= maxWeight) {
      curr[w] = value[0];
    } else {
      curr[w] = 0;
    }
  }

  for (int index = 1; index < n; index++) {
    for (int w = maxWeight; w >= 0; w--) {
      int include = 0;
      if (weight[index] <= w) {
        include = value[index] + curr[w - weight[index]];
      }
      int exclude = curr[w];
      curr[w] = max(include, exclude);
    } 
  }
  return curr[maxWeight];
} 
