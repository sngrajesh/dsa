#include <stdio.h>
#include <iostream>
#include <limits>
using namespace std;

int modifyHeight(int arr[],int n,int k)
{
	int answer ;
	int min=INT_MAX ,max=INT_MIN;

	for(int j =0 ; j<n ;j++)
	{
		if ((arr[j]-k)<=0)
		{
			arr[j]+=k;
		}
		else
		{
			arr[j]-=k;
		}
		if(arr[j] < min)
			min = arr[j];
		if(arr[j] > max)
			max = arr[j];
	}
	answer = max-min;
return answer;
}


int main(int argc, char *argv[])
{
	int n,k;
	int min = INT_MAX;
	int max = INT_MIN;
	printf("ENTER n : ");
	scanf("%d", &n);
	printf("ENTER k : ");
	scanf("%d", &k);
	int arr[n];
	for (int j = 0; j < n; j++)
	{
		printf("%d>>", j + 1);
		cin >> arr[j];
	}
	
	cout<<modifyHeight(arr,n,k)<<endl;
	
	for (int j = 0; j < n; j++)
	{
		cout << arr[j]<<" ";
	}
	return 0;
}