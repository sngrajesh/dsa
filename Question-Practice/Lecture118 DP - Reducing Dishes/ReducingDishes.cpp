class Solution {
public:
    int solveRecurssion(int index, int time, vector<int>& satisfaction) {
        if (index >= satisfaction.size())
            return 0;

        int include = (time + 1) * satisfaction[index] +
                      solveRecurssion(index + 1, time + 1, satisfaction);
        int exclude = solveRecurssion(index + 1, time, satisfaction);

        return max(include, exclude);
    }

    int solveMemoization(int index, int time, vector<int>& satisfaction,
                         vector<vector<int>>& dp) {
        if (index >= satisfaction.size())
            return 0;
        if (dp[index][time] != -1)
            return dp[index][time];

        int include = (time + 1) * satisfaction[index] +
                      solveMemoization(index + 1, time + 1, satisfaction, dp);
        int exclude = solveMemoization(index + 1, time, satisfaction, dp);

        dp[index][time] = max(include, exclude);
        return dp[index][time];
    }

    int solveTabulation(vector<int>& satisfaction, int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int time = n - 1; time >= 0; time--) {
                int include =
                    (time + 1) * satisfaction[index] + dp[index + 1][time + 1];
                int exclude = dp[index + 1][time];
                dp[index][time] = max(include, exclude);
            }
        }

        return dp[0][0];
    }

    int solveSpaceOptimized(vector<int>& satisfaction, int n) {
        vector<int>next(n + 1, 0);
        vector<int>curr(n + 1, 0);

        for (int index = n - 1; index >= 0; index--) {
            for (int time = n - 1; time >= 0; time--) {
                int include =
                    (time + 1) * satisfaction[index] + next[time + 1];
                int exclude = next[time];
                curr[time] = max(include, exclude);
            }
            next = curr;
        }
        return next[0];
    }

    int solveExtraSpaceOptimized(vector<int>& satisfaction, int n) {
        int ans=0;
        for(int i=0; i<n; i++){
           int sum=0;
           int time=1;
           for(int j=i; j<n; j++){
              sum+=satisfaction[j]*time;
              time++;
           }
        ans=max(ans,sum);
        }
        return ans;
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());

        /*
        //Recurssion
        return solveRecurssion(0, 0, satisfaction);
        */

        /*
        //Memoization
        vector<vector<int> >dp(n, vector<int>(n, -1));
        return solveMemoization(0, 0, satisfaction, dp);
        */

        /*
        // Tabulation
        return solveTabulation(satisfaction, n);
        */

        //Space Optimized
        return solveExtraSpaceOptimized(satisfaction, n);

    }
};
