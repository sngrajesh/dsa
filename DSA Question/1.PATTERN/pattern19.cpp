#include<iostream>
using namespace std;
int main(){
    //Solid  half Diamond pattern
    int n ; cin >> n ;
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < i ; j++ ) {
            cout << "*";
        }   
        cout << endl ;
    }
    for ( int i = n ; i >0 ; i-- ) {
        for ( int j = i ; j > 0  ; j-- ) {
            cout << "*";
        }   
        cout << endl ;
    }
    return 0;
}