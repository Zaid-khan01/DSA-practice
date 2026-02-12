#include <bits/stdc++.h>
using namespace std;

// ---------------- Disjoint Set ----------------
class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }
    
    int findUltimatePar(int node){
        if(parent[node] == node)
            return node;
        return parent[node] = findUltimatePar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ult_u = findUltimatePar(u);
        int ult_v = findUltimatePar(v);

        if(ult_u == ult_v) return;

        if(rank[ult_u] < rank[ult_v])
            parent[ult_u] = ult_v;
        else if(rank[ult_v] < rank[ult_u])
            parent[ult_v] = ult_u;
        else {
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }
};

class Solution {
public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet s(n*m);

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;

        vector<int> ans;

        for(auto it: operators){
            int row = it[0];
            int col = it[1];

            if(vis[row][col] == 1){
                ans.push_back(cnt);
                continue;
            }

            vis[row][col] = 1;
            cnt++;

            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};

            for(int i=0; i<4; i++){
                int adjr = row + delrow[i];
                int adjc = col + delcol[i];

                if(adjr>=0 && adjr<n && adjc>=0 && adjc<m){
                    if(vis[adjr][adjc] == 1){

                        int nodeNo = row*m + col;
                        int adjNodeNo = adjr*m + adjc;

                        if(s.findUltimatePar(nodeNo) != s.findUltimatePar(adjNodeNo)){
                            cnt--;
                            s.unionByRank(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};

int main() {
    int n = 4, m = 5;
    vector<vector<int>> operators = {
        {1, 1},
        {0, 1},
        {3, 3},
        {3, 4}
    };

    Solution s;
    vector<int> result = s.numOfIslands(n, m, operators);

    cout << "Number of islands after each operation:\n";
    for(int i : result){
        cout << i << " ";
    }

    return 0;
}
