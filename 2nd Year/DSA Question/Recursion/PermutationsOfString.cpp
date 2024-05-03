// PermutationsOfString.cpp
// https://www.codingninjas.com/studio/problems/permutations-of-a-string_985254

#include <bits/stdc++.h>
using namespace std;

void permuteSolve(string str, int i, vector<string> &ans) {
    if (i >= str.size()) {
        ans.push_back(str);
        return;
    }
    for (int j = i; j < str.size(); j++) {
        swap(str[j], str[i]);
        permuteSolve(str, i + 1, ans);
        swap(str[j], str[i]);
    }
}

vector<string> generatePermutations(string &str) {
    // write your code here
    vector<string> ans;
    permuteSolve(str, 0, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main(int argc, char const *argv[]) {
    string p = "rhd";
    vector<string> ans = generatePermutations(p);
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
    return 0;
}