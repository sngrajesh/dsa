// CheckPalindrom.cpp

#include <iostream>
#include <string.h>

using namespace std;

bool CheckPalindrom(string &str, int i, int j)
{
    if (i > j)
        return true;

    return (str[i] == str[j]) && CheckPalindrom(str, i + 1, j - 1);
}

int main(int argc, char const *argv[])
{
    string st;
    cout << "String input : ";
    getline(cin, st);
    cout << "Palindrome : " << CheckPalindrom(st, 0, st.size() - 1) << endl;
    return 0;
}
