// https://leetcode.com/problems/find-if-path-exists-in-graph/

class Solution {

    void DFSRec(vector<vector<int>> &adj, vector<bool> &visited, int s){
        visited[s] = true;
        cout << s << " ";
        for (int i : adj[s])
            if (visited[i] == false)
                DFSRec(adj, visited, i);
    }

public:

    void addEdge(vector<vector<int>> &adj, int s, int t){
        adj[s].push_back(t); 
        adj[t].push_back(s);
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for (auto &e : edges)
            addEdge(adj, e[0], e[1]);
        vector<bool> visited(adj.size(), false);
        DFSRec(adj, visited, source);
        return visited[source] && visited[destination]; 
    }
};
