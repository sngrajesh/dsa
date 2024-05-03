
#include <iostream>

using namespace std;

int main(){
    // C++ program for diamond pattern printing using numbers and stars
    int  count = 1, n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j < i)
                cout << count++ << "*";
            else
                cout << count++;
        }
        cout << endl;
    }
    count = count - n;
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j < i)
                cout << count++ << "*";
            else
                cout << count++;
        }
        count = (count + 1) - 2 * i;
        cout << endl;
    }

    return 0;
}