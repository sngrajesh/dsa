// https://leetcode.com/problems/min-cost-climbing-stairs/
class Solution {
public:
    int sloveUtil(int n, vector<int>& cost){
        if(n == 1 || n == 0 ) return cost[n];
        return cost[n] + min(sloveUtil(n-1 , cost), sloveUtil(n-2 , cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int ans = min(sloveUtil(n-1 , cost), sloveUtil(n-2 , cost));
        return ans;
    }

	/********************************* DP - Top Down ***************************************/	
    int sloveUtilDPMemoization(int n, vector<int>& cost, vector<int>dp){
        if(n == 1 || n == 0 ) return cost[n];
        if(dp[n] != -1) return dp[n];
        dp[n] = cost[n] + min(sloveUtil(n-1 , cost, dp), sloveUtil(n-2 , cost , dp));
        return dp[n];
    }
    int minCostClimbingStairsDPMemoization(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp( n+1 , -1);
        int ans = min(sloveUtil(n-1 , cost ,dp), sloveUtil(n-2 , cost , dp));
        return ans;
    }
	
	/********************************* DP - Bottom Up ***************************************/	
    int minCostClimbingStairsTabulation(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for(int i = 2 ; i < n ; i++){
            dp[i] = min(dp[i-1] , dp[i-2]) + cost[i];
        }

        return min(dp[n-1] , dp[n-2]);
    }
    
    /********************************* DP - Space Optimize ***************************************/	
    int minCostClimbingStairsSpaceOptimize(vector<int>& cost) {
        int n = cost.size();
        int prev1 = cost[0];
        int prev2 = cost[1];
        int curr ;
        for(int i = 2 ; i < n ; i++){
            curr = min(prev1 , prev2) + cost[i];
            prev1 = prev2;
            prev2 = curr;
        }
        return min(prev1 , prev2);
    } 

};


