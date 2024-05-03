// https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626

#include <bits/stdc++.h>

bool isCycleDFS(int src, 
                unordered_map<int, list<int>> &adj,
                unordered_map<int, bool> &visited,
                unordered_map<int, bool> &dfsVisited) {

  visited[src] = true;
  dfsVisited[src] = true;

  for (auto i : adj[src]) {
    if (!visited[i]) {
      bool ans = isCycleDFS(i, adj, visited, dfsVisited);
      if (ans)
        return true;
    } else if (visited[i]==true && dfsVisited[i] == true) {
      return true;
    }
  }
  dfsVisited[src] = false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
  unordered_map<int, list<int>> adj;
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i].first;
    int v = edges[i].second;
    adj[u].push_back(v);
  }

  unordered_map<int, bool> visited;
  unordered_map<int, bool> dfsVisited;

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      bool ans = isCycleDFS(i, adj, visited, dfsVisited);
      if (ans){ 
        return 1;
      }
    }
  }
  
  return 0;
}

