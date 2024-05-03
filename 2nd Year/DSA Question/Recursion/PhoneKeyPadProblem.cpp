// PhoneKeyPadProblem.cpp
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <bits/stdc++.h>
using namespace std;
class Solution {
   private:
    void letterCombinationsSolution(string digits, vector<string> &ans,
                                    vector<string> mapping, string output,
                                    int i) {
        if (i >= digits.size()) {
            if (output.size() > 0) ans.push_back(output);
            return;
        }
        int l = digits[i] - '2';
        for (int j = 0; j < mapping[l].size(); j++) {
            letterCombinationsSolution(digits, ans, mapping,
                                       output + mapping[l][j], i + 1);
        }
    }

   public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        vector<string> mapping{
            "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz",
        };
        string output = "";
        letterCombinationsSolution(digits, ans, mapping, output, 0);
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<string> ans = s.letterCombinations("2563");

    for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
    return 0;
}