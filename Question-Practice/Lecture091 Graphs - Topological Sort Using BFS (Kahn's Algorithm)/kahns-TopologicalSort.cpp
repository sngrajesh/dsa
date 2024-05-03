  #include <bits/stdc++.h> 

  vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
      unordered_map<int , list<int> >adj;
      for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v); 
      }

      vector<int>inDegree(v);

      for(auto edge : adj){
        for(auto nieghbour : edge.second){
          inDegree[nieghbour]++;
        }
      }

      queue<int>q;
      
      for(int i = 0;  i < v; i++){
          if(inDegree[i] == 0){
            q.push(i);
          }
      }

      vector<int> ans;

      while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for(auto nieghbour : adj[front]){
          inDegree[nieghbour]--;
          if(inDegree[nieghbour] == 0)
            q.push(nieghbour);
        }
      }

      return ans;
  }
