#include<iostream>
using namespace std;
int main(){
    //Character palindrome pattern
    int n ; cin >> n ;
    for ( int  i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j < i ; j++ ) {
            cout <<(char)('A' + j); 
        }
         for ( int j = i-2 ; j >= 0 ; j-- ) {
            cout <<(char)('A' + j); 
        }
        cout << endl ;
    }

    return 0;
}