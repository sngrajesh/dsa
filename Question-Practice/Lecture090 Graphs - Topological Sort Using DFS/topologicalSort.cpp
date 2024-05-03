// https://www.naukri.com/code360/problems/topological-sort_982938
#include <bits/stdc++.h>

void dfsTopoLogicalUtil(int node, unordered_map<int, list<int>> &adj,
                        vector<bool> &visited, stack<int> &st) {
  visited[node] = true;

  for (auto it : adj[node]) {
    if (!visited[it]) {
      dfsTopoLogicalUtil(it, adj, visited, st);
    }
  }
  st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
  vector<int> ans;
  unordered_map<int, list<int>> adj;
  vector<bool> visited(v , false);
  stack<int> st;
  for (auto i : edges) {
    int u = i[0];
    int v = i[1];
    adj[u].push_back(v);
  }

  for (int i = 0; i <v ; i++) {
    if (!visited[i]) {
      dfsTopoLogicalUtil(i, adj, visited, st);
    }
  }

  while (!st.empty()) {
    ans.push_back(st.top());
    st.pop();
  }
  return ans;
}
