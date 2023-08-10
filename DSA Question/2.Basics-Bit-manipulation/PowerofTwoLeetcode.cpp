#include<iostream>
#include<math.h>
#include<limits.h>
using namespace std;
 void isPowerOfTwo(int n) {
        
        int ans = 1;
        
        for(int i = 0; i <= 30; i++) {
            
            
            if(ans == n)
            {
                cout << "True" << endl;
                return;
            }
            if(ans < INT_MAX/2)
            ans = ans * 2;   
            
        }
        
    cout << "False";
    }
void powerOfTwoMy(int n){
     while( n != 0){
        if(n & 1 && n > 1){
            cout << "False" << endl;
        return;
        }
        if( n == 2){
            cout << "True" << endl;
            return;
        }
        n /= 2;
     }
    cout << "False" << endl;
}
int main(){
    int n ; cin >> n ;
   
    powerOfTwoMy(n);
    
    return 0;
}