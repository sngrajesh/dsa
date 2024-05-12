#include <bits/stdc++.h>
using namespace std;

long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {

  deque<int> maxi(k);
  deque<int> mini(k);

  // Addition of first k size window

  for (int i = 0; i < k; i++) {

    while (!maxi.empty() && nums[maxi.back()] <= nums[i])
      maxi.pop_back();

    while (!mini.empty() && nums[mini.back()] >= nums[i])
      mini.pop_back();

    maxi.push_back(i);
    mini.push_back(i);
  }
  long long ans = 0;

  ans += nums[maxi.front()] + nums[mini.front()];

  // remaining windows ko process karlo
  for (int i = k; i < n; i++) {

    // next window

    // removal
    while (!maxi.empty() && i - maxi.front() >= k) {
      maxi.pop_front();
    }

    while (!mini.empty() && i - mini.front() >= k) {
      mini.pop_front();
    }

    // addition

    while (!maxi.empty() && nums[maxi.back()] <= nums[i])
      maxi.pop_back();

    while (!mini.empty() && nums[mini.back()] >= nums[i])
      mini.pop_back();

    maxi.push_back(i);
    mini.push_back(i);

    ans += nums[maxi.front()] + nums[mini.front()];
  }
  return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        cout << sumOfMaxAndMin(arr, n, k) << endl;
    }
    return 0;
}
