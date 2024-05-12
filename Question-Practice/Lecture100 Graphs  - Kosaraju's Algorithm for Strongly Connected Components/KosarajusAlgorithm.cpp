// https://www.naukri.com/code360/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151


#include <bits/stdc++.h>

void dfs(int node, unordered_map<int, list<int>> &adj,
         unordered_map<int, bool> &visited, stack<int> &st) {
  visited[node] = true;

  for (auto nbr : adj[node]) {
    if (!visited[nbr]) {
      dfs(nbr, adj, visited, st);
    }
  }
  st.push(node);
}

void transposeDFS(int node, unordered_map<int, list<int>> &adj,
                  unordered_map<int, bool> &visited) {
  visited[node] = true;

  for (auto nbr : adj[node]) {
    if (!visited[nbr]) {
      transposeDFS(nbr, adj, visited);
    }
  }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges) {

  // Create a adjacency list
  unordered_map<int, list<int>> adj;
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i][0];
    int v = edges[i][1];
    adj[u].push_back(v);
  }

  // Topological Sort
  stack<int> st;
  unordered_map<int, bool> visited;
  for (int i = 0; i < v; i++) {
    if (!visited[i]) {
      dfs(i, adj, visited, st);
    }
  }

  // Transpose the adjacency list
  unordered_map<int, list<int>> transpose;
  for (int i = 0; i < v; i++) {
    for (auto nbr : adj[i]) {
      transpose[nbr].push_back(i);
    }
  }

  for(auto ele : visited){
	  visited[ele.first] = false;
  }


  // Call DFS using Tological Sorted Mannner
  int count = 0;
  while (!st.empty()) {
    int top = st.top();
    st.pop();
    if (!visited[top]) {
      count++;
      transposeDFS(top, transpose, visited);
    }
  }

  return count;
}
