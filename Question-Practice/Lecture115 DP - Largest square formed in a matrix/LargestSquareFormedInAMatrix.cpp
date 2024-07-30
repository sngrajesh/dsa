// https://www.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solveRecurssion(int n, int m, vector<vector<int>> &mat , int i , int j, int &maximum){
        if(i >= n || j >= m) return 0;
        
        int right = solveRecurssion(n, m, mat , i, j  + 1, maximum);
        int diagnol = solveRecurssion(n, m, mat , i + 1, j + 1 , maximum);
        int down = solveRecurssion(n, m, mat , i + 1, j , maximum);
        
        if(mat[i][j] == 0) return 0;
        
        int ans = 1 + min(right, min(diagnol, down));
        maximum = max(maximum , ans);
        
        return maximum;
    }
    
    int solveMemo(int n, int m, vector<vector<int>> &mat , int i , int j, int &maximum , vector<vector<int > >&dp){
        if(i >= n || j >= m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int right = solveMemo(n, m, mat , i, j  + 1, maximum,dp);
        int diagnol = solveMemo(n, m, mat , i + 1, j + 1 , maximum, dp);
        int down = solveMemo(n, m, mat , i + 1, j , maximum, dp);
        
        if(mat[i][j] == 0) return dp[i][j] = 0;
        
        dp[i][j] = 1 + min(right, min(diagnol, down));
        maximum = max(maximum , dp[i][j]);
         
        return dp[i][j];
    }
    
    int solveTabulation(int n, int m, vector<vector<int>> &mat){
        vector<vector<int > >dp(n + 1, vector<int>(m + 1, 0));
        int maximum = 0;
        for(int row  = n - 1; row >= 0; row--){
            for(int col = m - 1; col >= 0 ; col--){
                int right = dp[row][col + 1];
                int diagnol = dp[row + 1][col + 1];
                int down = dp[row + 1][col];
                
                if(mat[row][col] == 0) {
                    dp[row][col] = 0;
                    continue;
                }
                dp[row][col] = 1 + min(right, min(diagnol, down));
                maximum = max(maximum , dp[row][col]); 
            }
        }
        return maximum;
    }
    
 
    int solveSO(int n, int m, vector<vector<int>> &mat, int &maximum){
        vector<int> curr(m + 1, 0);
        vector<int> next(m + 1, 0);
        for(int row = n - 1; row >= 0; row--){
            for(int col = m - 1; col >= 0; col--){
                int right = curr[col + 1];
                int diagnol = next[col + 1];
                int down = next[col];
                
                if(mat[row][col] == 1) {
                    curr[col] = 1 + min(right, min(diagnol, down));
                    maximum = max(maximum , curr[col]); 
                }
                else {
                    curr[col] = 0;
                }
            }
            next = curr;
        }
        return next[0];
    }
    

    void solveO1Soace(int row, int col, vector<vector<int>> &mat, int &maxi){
          for(int i =row-1;i>=0;i--){
            for(int j =col-1;j>=0;j--){
                if(mat[i][j]==1 && i < row-1 && j < col-1){
                    mat[i][j]=1+min(
                        mat[i+1][j],    //Down
                        min(mat[i][j+1],//Right
                        mat[i+1][j+1])  //Diagnol
                        );
                }
                maxi=max(mat[i][j],maxi);
            }
         
        }
    }

    
    int maxSquare(int n, int m, vector<vector<int>> mat){
        /*
        // Recurssion
        int maximum = 0;
        solveRecurssion(n, m, mat , 0, 0, maximum);
        return maximum;
        */
        
        /*
        //Memoization
        int maximum = 0;
        vector<vector<int > >dp(n , vector<int>(m, -1));
        solveMemo(n, m, mat , 0, 0 , maximum, dp);
        return maximum;
        */
        
        /*
        //Tabulation
        return solveTabulation(n , m , mat);
        */
        
        /*
        //Space Optimization
        int maximum = 0;
        solveSO(n , m , mat, maximum);
        return maximum;
        */
        
        //O(1) Space Complexity
        int maximum = 0;
        solveO1Soace(n , m , mat, maximum);
        return maximum;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
