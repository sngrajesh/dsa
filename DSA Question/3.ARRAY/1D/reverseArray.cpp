#include <iostream>
#include<conio.h>
using namespace std;
void reverseArray(int arr[],int n)
{
	int t;
	for(int i=0;i<n/2;i++)
	{
		t=arr[i];
		arr[i]=arr[n-1-i];
		arr[n-1-i]=t;
	}
}
int main(int argc, char *argv[])
{
	int n;
	printf ("Center number of element : ");
	scanf ("%d",&n);
	int arr[n];
	for(int I = 0 ; I < n ; I++)
	{
		cout<<">>";
		cin>>arr[I];
	}
	reverseArray(arr,n);
	for(int I = 0 ; I < n ; I++)
	{
		cout<<arr[I]<<" ";
	}
}