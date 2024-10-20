// https://leetcode.com/problems/is-subsequence/
class Solution {
public:
    bool solve(string s , string t , int i  , int j, vector<vector<int>>&memo) {
        if(memo[i][j]  != -1)
            return true; 

        if(i>=s.length())
            return true;
        if(j>=t.length())
            return false;
         
        bool same = false;
        bool diff = false;

        if(s[i]==t[j])
            same =  solve(s , t, i+1 , j+1, memo);
        else
            diff =  solve(s , t , i  , j+1, memo);

        memo[i][j] = (same || diff) ? 1: 0; 
        return same || diff;
        
    }
    bool isSubsequence(string s, string t) {
        vector<vector<int>>memo(s.length()+1, vector<int>(t.length()+1,-1));
        return solve(s , t , 0 , 0, memo);
    }
};
