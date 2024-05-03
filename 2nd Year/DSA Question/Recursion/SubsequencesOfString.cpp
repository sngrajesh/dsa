// SubsequencesOfString.cpp
// https://www.codingninjas.com/studio/problems/subsequences-of-string_985087?leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
void subsequencesSolution(string str, vector<string> &ans, string output, int i)
{
    if (i >= str.size())
    {
        if (output.length() > 0)
        {
            ans.push_back(output);
        }
        return;
    }

    subsequencesSolution(str, ans, output, i + 1);
    output = output + str[i];
    subsequencesSolution(str, ans, output, i + 1);
}

vector<string> subsequences(string str)
{
    vector<string> ans;
    string output = "";
    subsequencesSolution(str, ans, output, 0);
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<string> ans = subsequences("abc");

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}