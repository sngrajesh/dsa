#include<iostream>
using namespace std;
int main(){
    //Triangle pattern start with m
    int m ; cin >> m ;
    int n ; cin >> n ;
    for(int i = 1 ; i <=n ; i++){
        for (int j = 1 ; j <= i ; j++){
            cout << m ;
        }  
        m++; 
        cout << endl ;
    }
    m -= 2;
    for(int i = n-1 ; i > 0 ; i--){
        for (int j = i ; j >=1  ; j--){
            cout << m ;
        }   
        m--;
        cout << endl ;
    }
}