// https://www.naukri.com/code360/problems/cycle-detection-in-undirected-graph_1062670

#include <bits/stdc++.h>
bool isCycleDFS(int src, unordered_map<int, list<int>> &adj,
                unordered_map<int, bool> &visited, int currParent) {
 
  visited[src] = true;
  
  for (auto i : adj[src]) {
    if (!visited[i]) {
      bool ans = isCycleDFS(i, adj,visited, src);
      if(ans)
        return true;
    }
    else if(i != currParent){ //i is visited but it is not the parent
        return true;
    }
  }
  return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m) {
  unordered_map<int, list<int>> adj;
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i][0];
    int v = edges[i][1];

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  unordered_map<int, bool> visited; 

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      bool ans = isCycleDFS(i, adj, visited, -1);
      if (ans)
        return "Yes";
    }
  }
  return "No";
}

