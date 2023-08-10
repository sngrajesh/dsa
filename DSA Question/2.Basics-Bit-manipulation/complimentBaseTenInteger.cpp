#include <iostream>
using namespace std;
int complimentBaseTenInteger(int n){
     int m = n ,mask = 0;
        
        if(n == 0)
            return 1;
        
        while( m!=0) {
            mask = (mask << 1) | 1;
            m = m >> 1;
        }
        
        return ((~n) & mask);
        
        

}
int  main(){
    int n ; cin >> n;
    cout << complimentBaseTenInteger(n);
    return 0;
}