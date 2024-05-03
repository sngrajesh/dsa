// CalcualtePower.cpp
#include <bits/stdc++.h>
using namespace std;

long long int CalcualtePower(int n, int power)
{
    // Base case
    if (power == 0)
        return 1;

    // Odd power
    if (power % 2)
        return n * CalcualtePower(n, power / 2) * CalcualtePower(n, power / 2);

    // Even power
    else
        return CalcualtePower(n, power / 2) * CalcualtePower(n, power / 2);
}

int main(int argc, char const *argv[])
{

    int n, power;
    cout << "Number : ";
    cin >> n;
    cout << "Power : ";
    cin >> power;
    cout << "Answer : " << CalcualtePower(n, power) << endl;

    return 0;
}