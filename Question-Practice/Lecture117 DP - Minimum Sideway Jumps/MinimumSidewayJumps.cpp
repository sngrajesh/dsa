// https://leetcode.com/problems/minimum-sideway-jumps/description/

class Solution {
public:
    int solveRec(int position, int lane, vector<int>& obstacles) {
        if (position == obstacles.size() - 1)
            return 0;

        if (obstacles[position + 1] != lane) {
            return solveRec(position + 1, lane, obstacles);
        } else {
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++) {
                if (i != lane && obstacles[position] != i) {
                    ans = min(ans, 1 + solveRec(position, i, obstacles));
                }
            }
            return ans; 
        }
    }

    int solveMemo(int position, int lane, vector<int>& obstacles, vector<vector<int> >&dp) {
        if (position == obstacles.size() - 1)
            return 0;

        if(dp[lane][position] != -1) return dp[lane][position];

        if (obstacles[position + 1] != lane) {
            return solveMemo(position + 1, lane, obstacles, dp);
        } else {
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++) {
                if (i != lane && obstacles[position] != i) {
                    ans = min(ans, 1 + solveMemo(position, i, obstacles, dp));
                }
            }
            dp[lane][position] = ans;
            return dp[lane][position]; 
        }
    }

    int solveTab(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int> >dp(4, vector<int>(n, 1e9));
        for(int i = 0 ; i <= 3 ;i++) 
            dp[i][n-1] = 0;

        for(int position = n-2 ; position >= 0; position--){
            for(int lane = 1 ; lane <= 3; lane++){
                if (obstacles[position + 1] != lane) {
                    dp[lane][position] =  dp[lane][position + 1];
                } else {
                    int ans = 1e9;
                    for (int i = 1; i <= 3; i++) {
                        if (i != lane && obstacles[position] != i && dp[i][position] != INT_MAX) {
                            //Reason why addded position+1 - https://youtu.be/dvTTtzamEEo?si=1KkeK08OL7U9Y2sF&t=2157
                            ans = min(ans, 1 + dp[i][position + 1]);
                        }
                    }
                    dp[lane][position] = ans;  
                }
            }
        }

        return min(dp[2][0] , min(
            1+ dp[1][0],
            1+ dp[3][0]
        ));
    }

    int solveSO(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int>curr(4, 1e9); 
        vector<int>next(4, 0);

        for(int position = n-2 ; position >= 0; position--){
            for(int lane = 1 ; lane <= 3; lane++){
                if (obstacles[position + 1] != lane) {
                    curr[lane] =  next[lane];
                } else {
                    int ans = 1e9;
                    for (int i = 1; i <= 3; i++) {
                        if (i != lane && obstacles[position] != i) {
                            ans = min(ans, 1 + next[i]);
                        }
                    }
                    curr[lane] = ans;  
                }
            }
            next = curr;
        }

        return min(next[2] , min(
            1+ next[1],
            1+ next[3]
        ));
    }

    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        
        /*
        //Recurssion 
        return solveRec(0, 2, obstacles); 
        */

        /*
        //Memoization
        vector<vector<int> >dp(4, vector<int>(n, -1));
        return solveMemo(0, 2, obstacles ,dp); 
        */
        
        /*
        //Tabulation
        return solveTab(obstacles);
        */

        //Space Optimized
        return solveSO(obstacles);
    }
};





