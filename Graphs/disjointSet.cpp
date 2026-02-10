#include<iostream>
#include<vector>
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
int main(int argc, char const *argv[])
{
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    ds.unionByRank(3, 7);

    // now check that ultimate parent of 3 and 7 is same or not
    if(ds.findUltimatePar(3) == ds.findUltimatePar(7)){
        cout<<"Yes! same parent";
    }
    else{
        cout<<"No! not same parent";
    }
    return 0;
}
