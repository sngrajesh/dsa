#include <iostream>
using namespace std;
int main()
{
    //Solid Reactangle
    int n, m;
    cout<<"Enter the number of rows and columns: ";
     cin >> n;
     cin >> m;
    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < m; i++)
        {
            std::cout << "*";
        }
        cout<< endl;
    }
    return 0;
}