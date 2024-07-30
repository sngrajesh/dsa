// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  static bool cmp(pair<double, Item>  a, pair<double, Item>  b){
      return a.first > b.first;
  }
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        
        vector<pair<double, Item>>v;
        for(int i = 0; i < n; i++){
            int val = arr[i].value;
            int weg = arr[i].weight;
            double perUnit = (1.0*val / weg);
            pair<double, Item> temp = make_pair(perUnit, arr[i]);
            v.push_back(temp);    
        }
        sort(v.begin(), v.end(), cmp);
        
        double totalValue = 0;
        for(int i = 0; i < n ; i++){
            if(v[i].second.weight > w){
                totalValue += w*v[i].first;
                w = 0;
            }else{
                totalValue += v[i].second.value; 
                w -= v[i].second.weight;
            }
        }
        
        return totalValue;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
