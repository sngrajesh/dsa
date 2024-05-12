// https://www.naukri.com/code360/problems/cut-into-segments_1214651

#include <climits>

/********************************** Recursion *******************************/
int solveRecursion(int n, int x, int y, int z) {
  if (n == 0)
    return 0;
  if (n < 0)
    return INT_MIN;

  int xAns = 1 + solve(n - x, x, y, z);
  int yAns = 1 + solve(n - y, x, y, z);
  int zAns = 1 + solve(n - z, x, y, z);

  int ans = max(xAns, max(yAns, zAns));

  return ans;
}

int cutSegmentsRecursion(int n, int x, int y, int z) {
  int ans = solve(n, x, y, z);
  if (ans < 0)
    return 0;
  return ans;
}



/********************************** DP - Top Down *******************************/
int solveMemo(int n, int x, int y, int z, vector<int> &dp) {
  if (n == 0)
    return 0;
  if (n < 0)
    return INT_MIN;

  if(dp[n] != -1) return dp[n];

  int xAns = 1 + solve(n - x, x, y, z, dp);
  int yAns = 1 + solve(n - y, x, y, z, dp);
  int zAns = 1 + solve(n - z, x, y, z, dp);

  dp[n] = max(xAns, max(yAns, zAns));

  return dp[n];
}

int cutSegmentsMemo(int n, int x, int y, int z) {
  vector<int> dp(n + 1, -1);
  int ans = solve(n, x, y, z, dp);
  if (ans < 0)
    return 0;
  return ans;
}






/********************************** DP - Top Down *******************************/
int solveTabulation(int n, int x, int y, int z) {

  vector<int> dp(n + 1, INT_MIN);
  dp[0] = 0;

  for (int i = 1; i <= n; i++) {
    if (i - x >= 0) 
      dp[i] = max(dp[i], dp[i - x] + 1);
    
    if (i - y >= 0) 
      dp[i] = max(dp[i], dp[i - y] + 1);
    
    if (i - z >= 0) 
      dp[i] = max(dp[i], dp[i - z] + 1);
  }

  if (dp[n] < 0)
    return 0;
  return dp[n];
}

int cutSegments(int n, int x, int y, int z) { 
	return solveTabulation(n, x, y, z); 
}

