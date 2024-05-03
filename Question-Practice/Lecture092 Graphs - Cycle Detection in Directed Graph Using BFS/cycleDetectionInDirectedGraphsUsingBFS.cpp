// https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626

#include <bits/stdc++.h>

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
  unordered_map<int, list<int>> adj;
  for (auto edge : edges) {
    int u = edge.first -1;
    int v = edge.second - 1;
    adj[u].push_back(v);
  }

  vector<int> inDegree(n);

  for (auto edge : adj) {
    for (auto nieghbour : edge.second) {
      inDegree[nieghbour]++;
    }
  }

  queue<int> q;

  for (int i = 0; i < n; i++) {
    if (inDegree[i] == 0) {
      q.push(i);
    }
  }

  int count = 0;
  while (!q.empty()) {
    int front = q.front();
    q.pop();
    count++;
    for (auto nieghbour : adj[front]) {
      inDegree[nieghbour]--;
      if (inDegree[nieghbour] == 0)
        q.push(nieghbour);
    }
  }
  return count != n;
}
