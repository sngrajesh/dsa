// https://www.naukri.com/code360/problems/create-a-graph-and-print-it_1214551

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges) {
    vector<vector<int>> ans(n);
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    vector<vector<int>> adj(n);  // Initialize adj with n empty vectors

    for (int i = 0; i < n; i++) {
        adj[i].push_back(i);  // Add the current node to its own adjacency list
        for (int j = 0; j < ans[i].size(); j++) {
            adj[i].push_back(
                ans[i][j]);  // Add the neighbors of the current node
        }
    }

    return adj;
}
