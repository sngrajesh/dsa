// https://www.naukri.com/code360/library/articulation-points-in-a-graph
#include <bits/stdc++.h>

using namespace std;

void dfs(int node, int parent,
         vector<int>& discoveryTime, vector<int>& lowestTime,
         unordered_map<int, bool>& visited,
         unordered_map<int, list<int>>& adj,
         int& timer, vector<int>& articulation_points) {
    visited[node] = true;
    discoveryTime[node] = lowestTime[node] = timer++;

    int child = 0;
    for (auto nbr : adj[node]) {
        if (nbr == parent)
            continue;

        if (!visited[nbr]) {
            dfs(nbr, node, discoveryTime, lowestTime, visited, adj, timer, articulation_points);
            lowestTime[node] = min(lowestTime[node], lowestTime[nbr]);
            if (lowestTime[nbr] >= discoveryTime[node] && parent != -1) {
                articulation_points[node] = 1;
            }
            child++;
        } else {
            lowestTime[node] = min(lowestTime[node], discoveryTime[nbr]);
        }
    }

    if (parent == -1 && child > 1) {
        articulation_points[node] = 1;
    }
}

int main() {
    int n = 5;
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(3, 4));
    edges.push_back(make_pair(0, 4));
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(1, 2));

    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    vector<int> discoveryTime(n);
    vector<int> lowestTime(n);
    vector<int> articulation_points(n, 0);
    int timer = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1, discoveryTime, lowestTime, visited, adj, timer, articulation_points);
        }
    }

    for (int i = 0; i < n; i++)
        if (articulation_points[i] != 0)
            cout << i << " ";
    cout << endl;

    return 0;
}
