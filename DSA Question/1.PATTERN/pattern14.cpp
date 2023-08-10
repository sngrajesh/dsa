#include<iostream>
using namespace std;
int main(){
    //Full hollow Numeric Pyramid 
    int n ; cin >> n ;
    for(int  i = 1 ; i <= n ; i++ ){
        for(int k = 0 ; k < (n - i) ; k++){
            cout << " " ;
        }
        for( int j = 1 ; j <= i ; j++){
            if(j == 1 || j == i || i == n){
                cout << j <<" ";
            }
            else{
                cout << "  " ;
            }
        }
             
        cout << endl ;
    }
    return 0;
}