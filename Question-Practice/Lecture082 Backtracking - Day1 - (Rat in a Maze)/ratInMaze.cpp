// https://www.naukri.com/code360/problems/rat-in-a-maze_1215030



#include <bits/stdc++.h>

bool isSafe(vector<vector<int>> &m, int n, vector<vector<int>> visited, int x,
            int y) {
  if ((x >= 0) && (y >= 0) && (x < n) && (y < n) && (visited[x][y] == 0) &&
      (m[x][y] == 1))
    return true;
  return false;
}

void findPathSolution(vector<vector<int>> &m, int n,
                      vector<vector<int>> visited, int x, int y, string path,
                      vector<string> &ans) {
  if (x == (n - 1) && y == (n - 1)) {
    ans.push_back(path);
    return;
  }
  visited[x][y] = 1;
  // up
  if (isSafe(m, n, visited, x - 1, y)) {
    path.push_back('U');
    findPathSolution(m, n, visited, x - 1, y, path, ans);
    path.pop_back();
  }
  // left
  if (isSafe(m, n, visited, x, y - 1)) {
    path.push_back('L');
    findPathSolution(m, n, visited, x, y - 1, path, ans);
    path.pop_back();
  }
  // right
  if (isSafe(m, n, visited, x, y + 1)) {
    path.push_back('R');
    findPathSolution(m, n, visited, x, y + 1, path, ans);
    path.pop_back();
  }
  // down
  if (isSafe(m, n, visited, x + 1, y)) {
    path.push_back('D');
    findPathSolution(m, n, visited, x + 1, y, path, ans);
    path.pop_back();
  }
  visited[x][y] = 0;
}

vector<string> searchMaze(vector<vector<int> > &arr, int n) {
  vector<string> ans;
  if (arr[0][0] == 0)
    return ans;

  vector<vector<int>> visited = arr;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      visited[i][j] = 0;

  string path = "";

  findPathSolution(arr, n, visited, 0, 0, path, ans);
  sort(ans.begin(), ans.end());
  return ans;
}
