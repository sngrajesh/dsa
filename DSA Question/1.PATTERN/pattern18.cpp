#include<iostream>
using namespace std;
int main(){
    //Solid Diamond pattern
    int n ; cin >> n ;

    for ( int i = 0 ; i <=n ; i++ ) {
        for(int j = 0 ; j < (n-i) ; j++){
            cout << " " ;
        }
        for ( int j = 0 ; j < i ; j++ ) {
            if(j == 0 || j == i-1){
                cout << "* ";
            }
            else{
                cout << "  ";
            }
        }   
        cout << endl ;
    }
    for ( int i = n ; i >0 ; i-- ) {
        for(int j = 0 ; j < (n - i) ; j++){
            cout << " " ;
        }
        for ( int j = i ; j > 0  ; j-- ) {
             if(j == i || j == 1){
                cout << "* ";
            }
            else{
                cout << "  ";
            }
        }   
        cout << endl ;
    }
    return 0;
}