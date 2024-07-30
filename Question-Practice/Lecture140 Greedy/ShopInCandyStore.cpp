// https://www.geeksforgeeks.org/problems/shop-in-candy-store1145/1

//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int minimumAmount(int candies[], int N, int K){
        int amount = 0;
        int i = 0;
        int j = N - 1;
        while(i <= j){
            amount += candies[i++];
            j -= K;
        }
        return amount;
    }
    
    int maximumAmount(int candies[], int N, int K){
        int amount = 0;
        int i = 0;
        int j = N - 1;
        while(i <= j){
            amount += candies[j--];
            i += K;
        }
        return amount;
    }
    
    vector<int> candyStore(int candies[], int N, int K){
        sort(candies, candies + N);
        
        vector<int> ans;
        ans.push_back(minimumAmount(candies, N, K));
        ans.push_back(maximumAmount(candies, N, K));
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends
