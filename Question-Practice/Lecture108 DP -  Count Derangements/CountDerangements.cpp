// https://www.naukri.com/code360/problems/count-derangements_873861

/***************************************** Recurssion ***************************************/
#define MOD 1000000007
long long int countDerangements(int n) {
    if(n == 1) return 0;
    if(n == 2) return 1;
    long long int ans = (((n-1)%MOD)*((countDerangements(n-1)%MOD) + (countDerangements(n-2)%MOD)) %MOD);
    return ans;
}

/***************************************** DP - Top Down ***************************************/
#include <vector>
#define MOD 1000000007

long long int solveMemo(int n, vector<long long int> &dp) {
  if (n == 1)
    return 0;
  if (n == 2)
    return 1;

  if (dp[n] != -1)
    return dp[n];

  dp[n] = (((n - 1) % MOD) *
           ((solveMemo(n - 1, dp) % MOD) + (solveMemo(n - 2, dp) % MOD)) % MOD);
  return dp[n];
}

long long int countDerangementsMemo(int n) {
  vector<long long int> dp(n + 1, -1);
  return solveMemo(n, dp);
}
/***************************************** DP - Bottom Up ***************************************/
#include <vector>
#define MOD 1000000007

long long int countDerangements(int n) {
  vector<long long int> dp(n + 1, -1);
  dp[1] = 0;
  dp[2] = 1;
  for (int i = 3; i <= n; i++)
    dp[i] = ((i - 1) % MOD * ((dp[i - 2]) % MOD + (dp[i - 1]) % MOD)) % MOD;

  return dp[n];
}
/***************************************** DP - Space Optimized ***************************************/
#define MOD 1000000007

long long int countDerangements(int n) {
  
  long long int currMinTwo = 0;  // dp[1]
  long long int currMinOne = 1;  // dp[2]
  for (int i = 3; i <= n; i++){
    long long int ans = ((i - 1) % MOD * (currMinTwo % MOD + currMinOne % MOD)) % MOD;
    currMinTwo = currMinOne;
    currMinOne = ans;
  }

  return currMinOne;;
}
