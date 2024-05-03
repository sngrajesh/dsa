#include <list>
#include <stack>
#include <vector>
#include <climits>
#include <iostream>
#include <unordered_map>

using namespace std;

class Graph {
   public:
    unordered_map<int, list<pair<int, int> > > adj;

    void addEdge(int u, int v, int w) {
        pair<int, int> p = make_pair(v, w);
        adj[u].push_back(p);
    }

    void printAdj() {
        for (auto i : adj) {
            cout << i.first << " -> ";
            for (auto j : i.second) {
                cout << "(" << j.first << "," << j.second << ")";
            }
            cout << endl;
        }
    }
    void depthFirstSearch(int node, unordered_map<int, bool> &visited,
                          stack<int> &st) {
        visited[node] = true;

        for (auto i : adj[node])
            if (!visited[i.first])  // Not visited node
                depthFirstSearch(i.first, visited, st);

        st.push(node);
    }

    void getShortestPath(int src, vector<int> &distance,
                         stack<int> &topoSortStack) {
        distance[src] = 0;
        while (!topoSortStack.empty()) {
            int top = topoSortStack.top();
            topoSortStack.pop();

            if (distance[top] != INT_MAX) {
                for (auto neig : adj[top]) {
                    if (distance[top] + neig.second < distance[neig.first]) {
                        distance[neig.first] = distance[top] + neig.second;
                    }
                }
            }
        }
    }
};

int main() {
    Graph G;
    int edges = 9;
    int vertex = 6;
    G.addEdge(1, 3, 6);
    G.addEdge(1, 2, 2);
    G.addEdge(0, 1, 5);
    G.addEdge(0, 2, 3);
    G.addEdge(3, 4, -1);
    G.addEdge(2, 4, 4);
    G.addEdge(2, 5, 2);
    G.addEdge(2, 3, 7);
    G.addEdge(4, 5, -2);

    int src = 1;

    unordered_map<int, bool> visited;
    stack<int> st;
    // Topological Sorting using DFS
    for (int i = 0; i < vertex; i++)
        if (!visited[i])  // Not visited node
            G.depthFirstSearch(i, visited, st); //Get Topologial Sorted Array Using DFS

    vector<int> distance(vertex);
    for (int i = 0; i < vertex; i++) distance[i] = INT_MAX;

    G.getShortestPath(src, distance, st);

    for (auto i : distance) cout << i << " ";
    cout << endl;

    return 0;
}
