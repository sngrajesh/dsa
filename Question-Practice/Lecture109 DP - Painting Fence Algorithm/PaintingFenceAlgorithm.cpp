// https://www.naukri.com/code360/problems/ninja-and-the-fence_3210208

#include <bits/stdc++.h> 
#define MOD 1000000007

/********************************* Recurssion *********************************/ 
int add(int a, int b){
    return (a%MOD + b%MOD)%MOD;
}

int mul(int a, int b){
    return (a%MOD * b%MOD)%MOD;
}

int solve(int n, int k) {
    if(n == 1) return k;
    if(n == 2) return add(k , mul(k , k-1));
    int ans = add(
        mul(solve(n-2, k), k-1),
        mul(solve(n-1, k), k-1)
    );
    return ans;
}

int numberOfWays(int n, int k) {
    return solve(n, k);
}

/********************************* DP - Top Down *********************************/ 
int addMemo(int a,int b){
    return ((a%MOD)+(b%MOD))%MOD;
} 

int multMemo(int num1, int num2){
    return ((num1%MOD) * 1LL * (num2%MOD))%MOD;
}
int solveMemo(int n,int k,vector<int>&dp){
    //base case
    if(n==1)
        return k;
    if(n==2)
        return addMemo(k,multMemo(k,k-1));
    if(dp[n]!=-1)
        return dp[n];

    dp[n]=addMemo(multMemo(solveMemo(n-2,k,dp),k-1),multMemo(solveMemo(n-1,k,dp),k-1));
    
    return dp[n];
}
int numberOfWaysMemo(int n, int k) {
    vector<int>dp(n+1,-1);
    return solveMemo(n,k,dp);
}

/********************************* DP - Bottom Up *********************************/ 

int addTab(int a,int b){
    return ((a%MOD)+(b%MOD))%MOD;
} 
int multTab(int num1, int num2){
    return ((num1%MOD) * 1LL * (num2%MOD))%MOD;
}
 
int numberOfWaysTab(int n, int k) {
    vector<int>dp(n+1,-1);
    dp[1] = k;
    dp[2] = addTab(k,multTab(k,k-1));

    for(int i = 3; i <= n; i++){
        dp[i] = addTab(multTab(dp[i-2],k-1),multTab(dp[i-1],k-1));
    }
    
    return dp[n];
} 

/********************************* DP - Space Optimize *********************************/ 

int addSO(int a, int b) { 
	return ((a % MOD) + (b % MOD)) % MOD; 
}
int multSO(int num1, int num2) {
  return ((num1 % MOD) * 1LL * (num2 % MOD)) % MOD;
}

int numberOfWaysSO(int n, int k) {

  int first = k;                       // i-2
  int second = addSO(k, multSO(k, k - 1)); // i-1

  for (int i = 3; i <= n; i++) {
    int ans = addSO(multSO(first, k - 1), multSO(second, k - 1));
    first = second;
    second = ans;
  }

  return second;
}

