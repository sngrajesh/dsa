// https://www.naukri.com/code360/problems/prim-s-mst_1095633

#include <bits/stdc++.h>

vector<pair<pair<int, int>, int> >calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g){

  // Write your code here.
  // create adajancency list
  unordered_map<int, list<pair<int, int>>> adj;
  for (int i = 0; i < m; i++){
    int u = g[i].first.first;
    int v = g[i].first.second;
    int w = g[i].second;
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }

  // create 3 data structures which was in this first for key value ds
  vector<int> key(n + 1); // Distance
  // second for mst
  vector<bool> mst(n + 1); // Visited
  // third for parents
  vector<int> parents(n + 1); // Parent

  // intialization the value
  for (int i = 0; i <= n; i++){
    key[i] = INT_MAX; // in starting put all value as max eg- infinite
    parents[i] = -1; // mark all value -1
    mst[i] = false; // mark all value false
  }

  // let start the algo
  // initially given test case start with one so source node taken as 1
  key[1] = 0;
  parents[1] = -1;
  
  for (int i = 1; i < n; i++){
    int mini = INT_MAX;
    int u;
    // find the min value
    for (int v = 1; v <= n; v++){
      if (mst[v] == false && key[v] < mini){
        u = v;
        mini = key[v];
      }
    }

    // mark mst in true
    mst[u] = true;
     
    // find its adjacent node
    for (auto it : adj[u]){
      int v = it.first;
      int w = it.second;
      if (mst[v] == false && w < key[v]){
        parents[v] = u;
        key[v] = w;
      }
    }
  }

  vector<pair<pair<int, int>, int>> ans;
  for (int i = 2; i <= n; i++){
    ans.push_back({{parents[i], i}, key[i]});
  }

  return ans;
}

