#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &s){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj, s);
            }
        }
        s.push(node);
    }

    void dfs3(int node, vector<int> &vis, vector<vector<int>> &adjT){
        vis[node] = 1;
        for(auto it: adjT[node]){
            if(!vis[it]){
                dfs3(it, vis, adjT);
            }
        }
    }

    int kosaraju(vector<vector<int>> &adj) {
        int V = adj.size();
        vector<int> vis(V, 0);
        stack<int> st;

        // Step 1: Order by finish time
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, vis, adj, st);
            }
        }
        
        // Step 2: Transpose graph or reverse the edges
        vector<vector<int>> adjT(V);
        for(int i=0; i<V; i++){
            vis[i] = 0;
            for(auto it: adj[i]){
                adjT[it].push_back(i);
            }
        }
        
        // Step 3: Count SCC
        int scc = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();

            if(!vis[node]){
                scc++;
                dfs3(node, vis, adjT);
            }
        }
        return scc;
    }
};

int main() {
    int V = 5;  // number of vertices
    vector<vector<int>> adj(V);

    // Example Directed Graph
    // 0 → 2
    // 2 → 1
    // 1 → 0
    // 0 → 3
    // 3 → 4

    adj[0].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(0);
    adj[0].push_back(3);
    adj[3].push_back(4);

    Solution s;
    int result = s.kosaraju(adj);
    cout << "Number of strongly connected components: " << result << endl;
    return 0;
}
