#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int timer = 0;

    void dfs(int node, int parent,
             vector<int> &vis,
             vector<int> &tin,
             vector<int> &low,
             vector<int> &mark,
             vector<int> adj[]) {

        vis[node] = 1;
        tin[node] = low[node] = timer++;
        int child = 0;

        for(auto it : adj[node]) {
            if(it == parent) continue;

            if(!vis[it]) {

                dfs(it, node, vis, tin, low, mark, adj);

                low[node] = min(low[node], low[it]);

                if(low[it] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }
                child++;
            }
            else {
                low[node] = min(low[node], tin[it]);
            }
        }
        if(parent == -1 && child > 1) {
            mark[node] = 1;
        }
    }

    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> tin(V);
        vector<int> low(V);
        vector<int> mark(V, 0);

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, -1, vis, tin, low, mark, adj);
            }
        }
        vector<int> ans;
        for(int i = 0; i < V; i++) {
            if(mark[i] == 1)
                ans.push_back(i);
        }
        if(ans.size() == 0) return {-1};
        return ans;
    }
};

int main() {
    int V = 5;  // number of vertices
    vector<int> adj[V];
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(2);
    adj[2].push_back(0);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[2].push_back(4);
    adj[4].push_back(2);

    Solution s;
    vector<int> result = s.articulationPoints(V, adj);

    cout << "Articulation Points: ";
    for(auto it : result) {
        cout << it << " ";
    }
    return 0;
}
