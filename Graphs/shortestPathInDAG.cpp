#include <bits/stdc++.h>
using namespace std;

class Solution {
private: 
    void topoSort(int node, vector<vector<pair<int,int>>>& adj, 
    vector<int>&vis, stack<int>&s){
        vis[node] = 1;
        for(auto it: adj[node]){
            int v = it.first;
            if(!vis[v]){
                topoSort(v, adj, vis, s);
            }
        }
        s.push(node);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        // adjacency list
        for(int i=0; i<E; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        
        // find topo sort
        vector<int> vis(V, 0);
        stack<int> s;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                topoSort(i, adj, vis, s);
            }
        }
        
        // do edge relaxation or finding shortest distance
        vector<int> dist(V, INT_MAX);
        
        dist[0] = 0;
        while(!s.empty()){
            int node = s.top();
            s.pop();
            
            for(auto it: adj[node]){
                int v = it.first;
                int wt = it.second;
                
                if(dist[node] != INT_MAX && dist[node] + wt < dist[v]){
                    dist[v] = dist[node] + wt;
                }
            }
        }
        
        // unreachable nodes
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) dist[i] = -1;
        }
        
        return dist;
    }
};


int main() {
    int V = 6;
    int E = 7;

    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 4, 1},
        {4, 5, 4},
        {4, 2, 2},
        {1, 2, 3},
        {2, 3, 6},
        {5, 3, 1}
    };

    Solution s;
    vector<int> ans = s.shortestPath(V, E, edges);

    cout << "Shortest distances from node 0:\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " -> " << ans[i] << endl;
    }

    return 0;
}