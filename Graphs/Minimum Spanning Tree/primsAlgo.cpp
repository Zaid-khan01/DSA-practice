#include <bits/stdc++.h>
using namespace std;

int primsAlgo(int V, vector<vector<pair<int,int>>> &adj) {
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    vector<int> vis(V, 0);
    pq.push({0, 0});   // {weight, node}

    int sum = 0;

    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        int wt = it.first;
        int node = it.second;

        if(vis[node]) continue;

        vis[node] = 1;
        sum += wt;

        for(auto it : adj[node]) {
            int adjNode = it.first;
            int edgeWt  = it.second;

            if(!vis[adjNode]) {
                pq.push({edgeWt, adjNode});
            }
        }
    }
    return sum;
}

int main() {
    int V = 5;

    vector<vector<pair<int,int>>> adj(V);

    // {src, dest, edges}
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    int sum = primsAlgo(V, adj);
    cout << "MST Weight = " << sum << endl;

    return 0;
}
