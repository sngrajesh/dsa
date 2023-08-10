#include <iostream>
using namespace std;
int main()
{
    int n; 
    cout << "Enter n : ";
    cin >> n;
    int arr[n];
    cout << "Enter arr : ";
    for (int j = 0; j < n; j++)
        cin >> arr[j];
    int maxi = INT32_MIN;
    for (int j = 0; j < n; j++){
        maxi =  max(arr[j] , maxi);
        cout << maxi << " " ;
    }
    return 0;
}