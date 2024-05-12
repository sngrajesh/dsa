// https://www.naukri.com/code360/problems/count-ways-to-reach-nth-stairs_798650

//Normal
#include <bits/stdc++.h> 

int solve(int nStairs , int i){
    if(i == nStairs) return 1;
    if(i > nStairs) return 0;
    return (solve(nStairs, i+1) + solve(nStairs, i+2));
}

int countDistinctWays(int nStairs) {
    return solve(nStairs, 0);
}




/*************************************************************************/

int countDistinctWaysInO1(int nStairs) {

    int n=nStairs;
    if(n == 0 || n==1){
        return 1;
    }

    int m = 1e9 + 7;
    int a=1;
    int b=1;
    int c;

    for(int i=2;i<=n;i++){
        c=(a+b)%m;
        a=b;
        b=c; 
    }
    return c;
}
