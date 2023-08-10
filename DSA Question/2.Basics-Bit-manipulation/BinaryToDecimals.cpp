#include <iostream>
#include <math.h>
using namespace std;

void binaryToDecimal(unsigned long int bin){
    int ans = 0;
    int i = 0;
    while(bin != 0){
        int k = bin % 10;
        ans += pow(2, i)*k;
        bin /= 10;
        i++;
    }
   cout << ans << endl;
}
 
int main(){
    unsigned long int bin ; cin >> bin;
    binaryToDecimal(bin);
    return 0;
}