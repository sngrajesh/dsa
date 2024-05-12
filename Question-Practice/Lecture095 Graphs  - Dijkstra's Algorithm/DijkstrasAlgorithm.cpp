//https://www.naukri.com/code360/problems/dijkstra-s-shortest-path_920469

#include <bits/stdc++.h> 
//Using Set
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    
    unordered_map<int , list<pair<int , int> > >adj;

    for(int i = 0 ; i < edges; i++){
        int u = vec[i][0]; 
        int v =vec[i][1];
        int w = vec[i][2];

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int>distance(vertices);
    for(int i = 0 ; i < vertices ; i++)
        distance[i] = INT_MAX;

    distance[source] = 0;
    set<pair<int, int> >st;
    st.insert({0,source}); // make_pair(0,0)

    while(!st.empty()){
        auto top = *(st.begin());
        int topDis = top.first;   
        int  topNode = top.second;
        st.erase(st.begin());

        for(auto neig : adj[topNode]){
            if(topDis + neig.second < distance[neig.first]){
                auto record = st.find(make_pair(neig.second, neig.first));
                if(record != st.end()){
                    st.erase(record);
                }
                distance[neig.first] = topDis + neig.second;
                st.insert({distance[neig.first] , neig.first});
            }
        }

    }


    return distance;
}



/*
    Time complexity: O(E*log(V))
    Space complexity: O(V^2)

    Where 'E' is the number of edges and 'V' is
    the number of vertices in a graph.
*/
/*
#include <bits/stdc++.h> 

class Compare
{
public:
    bool operator()(pair<int,int> a, pair<int,int> b)
    {
        return a.second>b.second;
    }
};

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    
    unordered_map<int , list<pair<int , int> > >adj;

    for(int i = 0 ; i < edges; i++){
        int u = vec[i][0]; 
        int v =vec[i][1];
        int w = vec[i][2];

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int>distance(vertices);
    for(int i = 0 ; i < vertices ; i++)
        distance[i] = INT_MAX;
    distance[source] = 0;

    vector<bool>visited(vertices);
    for(int i = 0 ; i < vertices ; i++)
        visited[i] = false; 

    //min heap - <node,distance> 
    priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;
    pq.push(make_pair(source, distance[source]));
 

    while(!pq.empty()){
        
        pair<int, int>top = pq.top();
        int  topNode = top.first;
        int topDis = top.second;   
        pq.pop();
        visited[topNode] = true;
        for(auto neig : adj[topNode]){
            if(!visited[neig.first] && (topDis + neig.second < distance[neig.first])){
                distance[neig.first] = topDis + neig.second;
                pq.push({ neig.first, distance[neig.first]});
            }
        }

    }
    return distance;
}
*/
