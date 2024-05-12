//https://www.naukri.com/code360/problems/house-robber_839733
#include <bits/stdc++.h> 

/********************************** Recurssion **********************************/
long long int solve(vector<int>& valueInHouse,int first, int last , int size){
    if(last == first) return valueInHouse[last];
    if(last < first) return 0;

    long long int include = valueInHouse[last] + solve(valueInHouse, first, last-2, size); 
    long long int exclude = solve(valueInHouse, first, last-1, size) + 0;
    return max(include, exclude);
}

long long int houseRobber(vector<int>& valueInHouse ){
    int n = valueInHouse.size();
    if(n == 1) return (long long int)valueInHouse[0];
    long long int first = solve(valueInHouse, 0, n-2 , n);
    long long int second = solve(valueInHouse, 1, n-1, n);
    return max(first, second);
}


// Refer lecture 105 Question 
/********************************** DP - Optimized **********************************/
#include <bits/stdc++.h> 
long long int solve(vector<int> &nums) {
  int n = nums.size();

  if (n == 0)
    return 0;

  long long int prev2 = 0;
  long long int prev1 = nums[0];

  for (int i = 1; i < n; i++) {
    long long  inc = prev2 + nums[i];
    long long  exc = prev1;

    long long  ans = max(inc, exc);
    prev2 = prev1;
    prev1 = ans;
  }
  return prev1;
}


long long int houseRobber(vector<int>& valueInHouse)
{
   int n = valueInHouse.size();
   if(n == 1) return valueInHouse[0];

   vector<int>first;
   vector<int>second;
   
   for(int i = 0 ; i < n-1; i++)first.push_back(valueInHouse[i]);
   for(int i = 1 ; i < n; i++)second.push_back(valueInHouse[i]); 

    return max(solve(first), solve(second));
}
