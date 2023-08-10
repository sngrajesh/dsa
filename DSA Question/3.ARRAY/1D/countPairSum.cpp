#include<iostream>
using namespace std;

int countPair(int n,int k, int arr[])
{
	int r=0;
	for(int a=0 ; a<n ; a++)
		for(int b=0 ; b<a ; b++)
			if(arr[a]+arr[b] == k)
			r++;
	return r;	
}


int main(int argc, char *argv[])
{
	int n;
	cin>>n;
	int k;
	cin>>k;
	int arr[n];
	for(int a=0 ; a<n ; a++)
		cin>>arr[a];
	cout<<countPair(n,k,arr);
	return 0;
}