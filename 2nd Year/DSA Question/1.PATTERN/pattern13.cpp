#include<iostream>
using namespace std;
int main(){
    //Full Numeric Pyramid 
    int n ; cin >> n ;
    for(int  i = 0 ; i < n ; i++ ){
          for (int j = (n - i); j >0 ; j-- ){
            cout << ' ';
           
        }
        for (int j = 0 ; j <= i ; j++ ){
            cout << i + j + 1;
           
        }
        for (int j = i ; j > 0  ; j-- ){
           cout << j+i;
        }
             
        cout << endl ;
    }
    return 0;
}