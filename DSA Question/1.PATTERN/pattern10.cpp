#include<iostream>
using namespace std;

int main(){
    //Half Inverse Pyramid Numeric
    int n ; cin >> n ;
    for(int  i = n ; i > 0 ; i-- ){
        for (int j = 0 ; j < i ; j++ )
            cout << j+1 ;
        cout << endl ;
    }
    return 0;
}