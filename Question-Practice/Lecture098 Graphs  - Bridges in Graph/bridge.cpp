// https://www.naukri.com/code360/problems/bridges-in-graph_893026

#include <list>
#include <unordered_map>
#include <vector>

void dfs(int node, int parent, int &timer, std::vector<int> &disc,
         std::vector<int> &low, std::vector<std::vector<int>> &result,
         std::unordered_map<int, std::list<int>> &adj,
         std::unordered_map<int, bool> &vis) {
    vis[node] = true;
    disc[node] = low[node] = timer++;

    for (auto neighbour : adj[node]) {
        if (neighbour == parent) continue;

        if (!vis[neighbour]) {
            dfs(neighbour, node, timer, disc, low, result, adj, vis);
            
            low[node] = std::min(low[node], low[neighbour]);

            // CHECK EDGE IS BRIDGE
            if (low[neighbour] > disc[node]) {
                std::vector<int> ans;
                ans.push_back(node);
                ans.push_back(neighbour);
                result.push_back(ans);
            }
        } else {
            // BACK EDGE
            low[node] = std::min(low[node], disc[neighbour]);
        }
    }
}

std::vector<std::vector<int>> findBridges(std::vector<std::vector<int>> &edges,
                                          int v, int e) {
    // CREATE ADJACENCY LIST
    std::unordered_map<int, std::list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    std::vector<int> disc(v);
    std::vector<int> low(v);
    int parent = -1;
    std::unordered_map<int, bool> vis;

    for (int i = 0; i < v; i++) {
        disc[i] = -1;
        low[i] = -1;
    }

    std::vector<std::vector<int>> result;

    // DFS
    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            dfs(i, parent, timer, disc, low, result, adj, vis);
        }
    }

    return result;
}
