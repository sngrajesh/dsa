#include <bits/stdc++.h>
using namespace std;

int minSwap1(int *arr, int n, int k) {
     
    // Find count of elements which are less than equals to k
    //2, 7, 9, 5, 8, 7, 4   count=3
    int count = 0;
    for (int i = 0; i < n; ++i)
        if (arr[i] <= k)
            ++count;
     
    // Find unwanted elements in current window of size 'count'
    //2, 7, 9, 5, 8, 7, 4    bad=2

    int bad = 0;
    for (int i = 0; i < count; ++i)
        if (arr[i] > k)
            ++bad;
     
    // Initialize answer with 'bad' value of current window
    int ans = bad;
    for (int i = 0, j = count; j < n; ++i, ++j) {
         
        // Decrement count of previous window
        if (arr[i] > k)
            --bad;
         
        // Increment count of current window
        if (arr[j] > k)
            ++bad;
         
        // Update ans if count of 'bad' is less in current window
        ans = min(ans, bad);
    }
    return ans;
}


int main(){

    int arr[] = {2, 1, 5, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << minSwap1(arr, n, k) << "\n";
     
    int arr1[] = {2, 7, 9, 5, 8, 7, 4};
    n = sizeof(arr1) / sizeof(arr1[0]);
    k = 5;
    cout << minSwap1(arr1, n, k);

    return 0;
}
