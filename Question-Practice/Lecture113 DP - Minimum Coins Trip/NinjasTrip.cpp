// https://www.naukri.com/code360/problems/minimum-coins_2180776

/****************************** Recurssion ******************************/
int solveRecurssion(int n, vector<int> days, vector<int> cost, int index) {
  if (index >= n)
    return 0;

  // For 1 Day Ticket
  int ans1 = cost[0] + solveRecurssion(n, days, cost, index + 1);

  // For 2 Days Ticket
  int i;
  for (i = index; i < n && days[i] < days[index] + 7; i++);
  int ans2 = cost[1] + solveRecurssion(n, days, cost, i);

  // For 30 Days Ticket
  int j;
  for (j = index; j < n && days[j] < days[index] + 30; j++);
  int ans3 = cost[2] + solveRecurssion(n, days, cost, j);

  return min(ans1, min(ans2, ans3));
}

int minimumCoinsRecurssion(int n, vector<int> days, vector<int> cost) {
  return solveRecurssionRecurssion(n, days, cost, 0);
}


/****************************** DP - Top Down ******************************/
int solveMemo(int n, vector<int> days, vector<int> cost, int index,
                    vector<int> &dp) {
  if (index >= n)
    return 0;

  if (dp[index] != -1)
    return dp[index];

  // For 1 Day Ticket
  int ans1 = cost[0] + solveMemo(n, days, cost, index + 1, dp);

  // For 2 Days Ticket
  int i;
  for (i = index; i < n && days[i] < days[index] + 7; i++)
    ;
  int ans2 = cost[1] + solveMemo(n, days, cost, i, dp);

  // For 30 Days Ticket
  int j;
  for (j = index; j < n && days[j] < days[index] + 30; j++)
    ;
  int ans3 = cost[2] + solveMemo(n, days, cost, j , dp);

  dp[index] =  min(ans1, min(ans2, ans3));
  return dp[index];
}

int minimumCoinsMemo(int n, vector<int> days, vector<int> cost) {
  vector<int> dp(n, -1);
  return solveMemo(n, days, cost, 0, dp);
}
/****************************** DP - Bottom Up ******************************/
int solveTabulation(int n, vector<int> days, vector<int> cost) {
  vector<int> dp(n + 1, INT_MAX);
  dp[n] = 0;

  for (int index = n - 1; index >= 0; index--) {
    // For 1 Day Ticket
    int ans1 = cost[0] + dp[index + 1];

    // For 2 Days Ticket
    int i;
    for (i = index; i < n && days[i] < days[index] + 7; i++)
      ;
    int ans2 = cost[1] + dp[i];

    // For 30 Days Ticket
    int j;
    for (j = index; j < n && days[j] < days[index] + 30; j++)
      ;
    int ans3 = cost[2] + dp[j];

    dp[index] = min(ans1, min(ans2, ans3));
  }
    return dp[0];
}

int minimumCoinsTabulation(int n, vector<int> days, vector<int> cost) {
  return solveTabulation(n, days, cost);
}
/*************************** DP - Space Optimized ***************************/
int solveSpaceOptimized(int n, vector<int> days, vector<int> cost) {
  int ans = 0;

  queue<pair<int, int>> week;
  queue<pair<int, int>> month;

  for (auto day : days) {

    // Step 1: Remove Expired Days
    while (!month.empty() && month.front().first + 30 <= day)
      month.pop();

    while (!week.empty() && week.front().first + 7 <= day)
      week.pop();

    // Step 2: Add cost till current date
    week.push(make_pair(day, ans + cost[1]));
    month.push(make_pair(day, ans + cost[2]));

    // Step 3: Ans update
    ans = min(ans + cost[0], min(week.front().second, month.front().second));
  }
  return ans;
}

int minimumCoinsSO(int n, vector<int> days, vector<int> cost) {
  return solveSpaceOptimized(n, days, cost);
}
