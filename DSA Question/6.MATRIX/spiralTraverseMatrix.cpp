#include <iostream>
using namespace std;
int r = 4;
int c = 4;

void traverse(int arr[r][c],int i , int j , int m , int n){
    if(i >= m or j >= n){
        return;
    }
    for( int p = j ; p < n ; p++){
        cout<< arr[i][p];
    }
    for( int p = i + 1 ; p < m ; p++){
        cout<< arr[p][n-1];
    }
    if((m - 1) != i){
        for(int  p = n-2 ; p >= j ; p--){
            cout << arr[m-1][p];
        }
    }
    if((n - 1) != j){
        for(int  p = m-2 ; p > i ; p--){
            cout << arr[p][j];
        }
    }
    traverse(arr , i+1 , j+1 , m-1 , n-1);
}

int main(){
     cin >> r;
     cin >> c;
    int arr[r][c];
    for( int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            cin >> arr[i][j];
        }
    }
    traverse(arr ,0 , 0 , r , c);
    return 0;
}