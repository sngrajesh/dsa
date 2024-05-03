#include <iostream>
#include <string.h>

using namespace std;

string ReverseString(string &st, int size)
{
    if (size == 0)
        return "";
    return st[size - 1] + ReverseString(st, size - 1);
}

// Babbar Solution
void reverse(string &str, int i, int j)
{
    if (i > j)
        return;

    swap(str[i], str[j]);
    i++;
    j--;

    reverse(str, i, j);
}

int main(int argc, char const *argv[])
{
    string st;
    cout << "String input" << endl;
    getline(cin, st);
    cout << "Reversed String : " << ReverseString(st, st.size()) << endl;
    return 0;
}

// ReverseString