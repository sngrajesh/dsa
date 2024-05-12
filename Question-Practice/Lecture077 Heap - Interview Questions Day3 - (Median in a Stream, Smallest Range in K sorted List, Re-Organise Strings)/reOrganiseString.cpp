
// https://www.naukri.com/code360/problems/rearrange-string_982765

/*
	Time Complexity  : O(N * log(N))
	Space Complexity : O(N)

	Where N is the total number of elements in the string.
*/


#include <bits/stdc++.h>
string reArrangeString(string &s) {
  unordered_map<char, int> mp;
  for (int i = 0; i < s.size(); i++)
    mp[s[i]]++;

  priority_queue<pair<int, char>> pq;

  for (auto i : mp)
    pq.push(make_pair(i.second, i.first));

  string ans = "";

  while (pq.size() > 1) {
    pair<int, char> top1 = pq.top();
    pq.pop();
    pair<int, char> top2 = pq.top();
    pq.pop();

    ans += top1.second;
    ans += top2.second;

    top1.first--;
    top2.first--;

    if (top1.first > 0)
      pq.push(top1);

    if (top2.first > 0)
      pq.push(top2);
  }

  if (!pq.empty()) {
    if (pq.top().first > 1) {
      return "not possible";
    }
    else {
      ans += pq.top().second;
      pq.pop();
    }
  }

  return ans;
}



