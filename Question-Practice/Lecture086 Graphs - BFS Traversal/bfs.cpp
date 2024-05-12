// https://www.naukri.com/code360/problems/bfs-in-graph_973002

#include <bits/stdc++.h>

vector<int> bfsTraversal(int n, vector<vector<int>> &adj) {

  queue<int> q; // DS use for BFS aleays

  vector<bool> v(n, false); // none node visited

  vector<int> ans;

  q.push(0); // first node visited,push visited node

  v[0] = true;

  for (int i = 0; i < n; i++) {

    while (!q.empty()) {

      int front = q.front();

      q.pop(); // node which are place inside ANS remove from queue

      ans.push_back(front);

      // neighbour element of 'front'

      for (int j = 0; j < adj[front].size(); j++) {

        if (!v[adj[front][j]]) {

          q.push(adj[front][j]);

          v[adj[front][j]] = true;
        }
      }
    }
  }

  return ans;
}
