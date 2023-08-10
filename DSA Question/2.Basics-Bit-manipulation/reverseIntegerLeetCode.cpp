#include <iostream>
#include <limits.h>
using namespace std;
void reverseAnIntergerMy(int n)
{
    int ans = 0;
    int i = 0;
    while (n)
    {
        int k = n % 10;
        ans = 10 * ans + k;
        i++;
        n = n / 10;
    }
    cout << ans << endl;
}
int main()
{
    int n;
    cin >> n;
    if ((n > INT_MAX / 10) || (n < INT_MIN / 10))
    {
        cout << 0 << endl;
        return 0;
    }
    reverseAnIntergerMy(n);
    return 0;
}