#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank, parent;
public: 
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i=0; i<=n; i++ ){
            parent[i] = i;
        }
    }

    int findUltimatePar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUltimatePar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ult_u = findUltimatePar(u);
        int ult_v = findUltimatePar(v);

        if(ult_u == ult_v) return;

        if(rank[ult_u] < rank[ult_v]){
            parent[ult_u] = ult_v;
        }
        else if(rank[ult_v] < rank[ult_u]){
            parent[ult_v] = ult_u;
        }
        else{
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }
};

int kruskalMST(int V, vector<vector<int>>& edges) {
    // sort edges by weight
    sort(edges.begin(), edges.end(),
         [](vector<int>& a, vector<int>& b) {
             return a[2] < b[2];
         });

    DisjointSet ds(V);
    int mstWeight = 0;

    for (auto &e : edges) {
        int u = e[0];
        int v = e[1];
        int wt = e[2];

        if (ds.findUltimatePar(u) != ds.findUltimatePar(v)) {
            mstWeight += wt;
            ds.unionByRank(u, v);
        }
    }
    return mstWeight;
}

int main(int argc, char const *argv[])
{
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };

    cout << "MST Weight: " << kruskalMST(V, edges);
    return 0;
}
