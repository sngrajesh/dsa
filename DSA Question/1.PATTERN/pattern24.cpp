#include<iostream>
using namespace std; 
int main(){
    int n ; cin >> n ;
    int count = n + 1;
    for (int i = 1 ; i < n ;  i++){
        for (int j = 1 ; j <= count ; j++){
            cout << "*";
        }
        for (int j = 1 ; j <= i ; j++){
            if(j == 1)
                cout << i;
            else
                cout << "*" << i;
        }
        for (int j = 1 ; j <= count ; j++){
            cout << "*";
        }
        cout << endl;
        count--;
    }
}