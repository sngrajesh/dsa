/*
Given a Integer array A[] of n elements. Your task is to complete the function PalinArray. 
Which will return 1 if all the elements of the Array are palindrome otherwise it will return 0.

Input:
2 ->Test cases

5 ->TestCase1
111 222 333 444 555

3 ->TestCase2
121 131 20

Output:
1
0
*/

#include<iostream>
#include<string.h>
using namespace std;
int PalinArray(int a[], int n);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		cout<<PalinArray(a,n)<<endl;
	}

    return 0;
}

bool checkPalindrome( int a ){
    int d = a;
    int sum = 0;
    int r = 0;
    while( d > 0){
        r = d%10;
        sum = (sum*10) + r ;
        d /= 10 ;

    }

    if(sum == a){
        return true;
    }

    return false;

}

int PalinArray(int a[], int n){

    for( int i = 0 ; i < n ; i++ ){
        if(!checkPalindrome(a[i])){
            return false;
        }
    }

    return true;

}