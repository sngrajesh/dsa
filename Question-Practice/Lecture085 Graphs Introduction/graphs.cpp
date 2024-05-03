#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

template <typename T>

class graph {
    unordered_map<T, list<T> > adj;

   public:
    void addEdge(T u, T v, int direction) {
        // direction -> 0 / 1 -> undirected / directed

        adj[u].push_back(v);

        if (direction == 0) {
            adj[v].push_back(u);
        }
    }

    void printAdjList() {
        for (auto i : adj) {
            cout << i.first << " -> "; 
            for (auto j : i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Ented the number of Nodes : ";
    cin >> n;

    int m;
    cout << "Ented the number of Edges : ";
    cin >> m;

    graph<int> g;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // Creation of edge
        g.addEdge(u, v, 0);
    }

    g.printAdjList();
}
