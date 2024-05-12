// https://www.naukri.com/code360/problems/bellmon-ford_2041977
vector<int> bellmonFord(int V, int m, int src, vector<vector<int>> &edges) {

  vector<int> dist(V + 1, 1e8);
  dist[src] = 0;
  for (int i = 0; i < V - 1; i++) {
    for (int j = 0; j < m; j++) {
      int u = edges[j][0];
      int v = edges[j][1];
      int w = edges[j][2];
      if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
      }
    }
  }

  int isCycle = false;
  for (int j = 0; j < m; j++) {
    int u = edges[j][0];
    int v = edges[j][1];
    int w = edges[j][2];
    if (dist[u] + w < dist[v]) {
      dist[v] = dist[u] + w;
      isCycle = true;
    }
  }

  return dist;
}
