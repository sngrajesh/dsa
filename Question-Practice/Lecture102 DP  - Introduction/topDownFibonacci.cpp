// https://www.naukri.com/code360/problems/nth-fibonacci-number_74156
#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n , vector<int>&dp){
    if(n == 0 || n == 1) return n;
    if(dp[n] != -1) return dp[n];
    dp[n] =  fibonacci(n-1, dp) + fibonacci(n-2, dp) ;
    return dp[n];
}


int main()
{
    int n; cin >> n;
    vector<int>dp(n+1); 
    for(int i = 0 ; i <= n; i++ ) dp[i] = -1;
    int ans = fibonacci(n , dp);
    cout << ans << endl;        
}
