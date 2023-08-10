#include<iostream>
using namespace std;

int main(){
    //Half Inverse Hollow Pyramid Numeric
    int n ; cin >> n ;
    for(int  i = n ; i > 0 ; i-- ){
        for (int j = 1 ; j <= i ; j++ ){
            if(j==1 || j==i || i==n)
                cout << j ;
            else
                cout << " " ;
        }
        cout << endl ;
    }
    return 0;
}