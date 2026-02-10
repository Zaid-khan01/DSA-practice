#include<iostream>
#include<vector>
using namespace std;

class DisjointSet{
    vector<int> size, parent;
public: 
    DisjointSet(int n){
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++ ){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUltimatePar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUltimatePar(parent[node]);
    }

    void unionBySize(int u, int v){
        int ult_u = findUltimatePar(u);
        int ult_v = findUltimatePar(v);

        if(ult_u == ult_v) return;

        if(size[ult_u] < size[ult_v]){
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
        else{
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
};
int main(int argc, char const *argv[])
{
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    ds.unionBySize(3, 7);

    // now check that ultimate parent of 3 and 7 is same or not
    if(ds.findUltimatePar(3) == ds.findUltimatePar(7)){
        cout<<"Yes! same parent";
    }
    else{
        cout<<"No! not same parent";
    }
    return 0;
}
