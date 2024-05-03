// https://www.codingninjas.com/studio/problems/check-palindrome_920555?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_13&leftPanelTabValue=SUBMISSION

#include <bits/stdc++.h>

using namespace std;

string bin(long long int n)
{
    string ans;
    while (n > 0)
    {
        ans = (to_string(n & 1)) + ans; 
        n >>= 1;
    }

    return ans;
}

// This function returns true if binary
// representation of x is palindrome
bool checkPalindrome(long long int n)
{
    string s1 = bin(n);
    string s2 = s1;

    // reversing the string 1
    reverse(s2.begin(), s2.end());
    return s1 == s2;
}

int main(int argc, char const *argv[])
{
    long long int N;
    cout << "Number input : ";
    cin >> N;
    cout << "Palindrome : " << checkPalindrome(N) << endl;
    return 0;
}
