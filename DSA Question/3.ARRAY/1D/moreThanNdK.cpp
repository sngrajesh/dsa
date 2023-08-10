#include <unordered_map>
#include <vector>
#include <iostream>
#include <map>
using namespace std;


void moreThanNdK_1(int arr[],int n,int k)
{
	int m = arr[0];
	for (int I = 1; I < n; I++)
	{
		m = max(arr[I], m);
	}
	
	vector<int> arr2(m,0);

	for (int a = 0; a < n; a++)
		arr2[arr[a]] += 1;

	for (int b = 0; b <= m; b++)
	{
		if (arr2[b] > (n / k))
			cout << b << " ";
	}
}




void morethanNbyK_2(int arr[], int n, int k)
{
    int x = n / k;
     
      // unordered_map initialization
    unordered_map<int, int> freq;
 
    for(int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
   
      // Traversing the map
    for(auto i : freq)
    {
         
        // Checking if value of a key-value pair is greater than x (where x=n/k)
        if (i.second > x)
        {
             
            // Print the key of whose value is greater than x
            cout << i.first << " ";
        }
    }
}





void morethanNbyK_3(int arr[], int n, int k)
{
 
    // Calculating n/k
    int x = n / k;
 
    // Counting frequency of every element using Counter
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]] += 1;
 
    // Traverse the map and print all the elements with occurrence more than n/k times
    for (int it = 0; it < mp.size(); it++) {
        if (mp[it] > x)
            cout << (it) << " ";
    }
}
 



int main(int argc, char *argv[])
{
	int n;
	printf("Enter N: ");
	scanf("%d", &n);
	int k;
	printf("Enter K : ");
	scanf("%d", &k);
	int arr[n];
	for (int I = 0; I < n; I++)
	{
		printf(">>");
		cin >> arr[I];
	}
	
	moreThanNdK_1(arr, n, k);
	cout<<endl;
	morethanNbyK_2(arr, n,k);
	cout<<endl;
	morethanNbyK_3(arr, n,k);
	return 0;
}
