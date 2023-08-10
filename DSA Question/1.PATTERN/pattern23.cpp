#include <iostream>
using namespace std;

int main()
{
    int i, j, N;
    cin >> N;
    cout << "*\n";
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= i; j++)
        {
            if (j == 1)
                cout << "*";
            cout << j;
        }
        for (j = i - 1; j >= 1; j--)
        {
            cout << j;
        }
        cout << "*";
        cout << endl;
    }

    for (i = N - 1; i >= 1; i--)
    {
        for (j = 1; j <= i; j++)
        {
            if (j == 1)
                cout << "*";
            cout << j;
        }
        for (j = i - 1; j >= 1; j--)
        {
            cout << j;
        }
        cout << "*";
        cout << endl;
    }
    cout << "*\n";
    return 0;
}