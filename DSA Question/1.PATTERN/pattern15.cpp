#include<iostream>
using namespace std;

int main(){
    //Half Hollow Pyramid Numeric
    int n ; cin >> n ;
    for(int  i = 1 ; i <= n   ; i++ ){
        for (int j = i ; j <= n; j++ ){
            if(j==i || j==n || i == 1){
                cout << "*";
            }
            else{
                cout << " ";
            }
        }
        cout << endl ;
    }
    return 0;
}