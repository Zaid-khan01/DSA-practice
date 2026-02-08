#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        int INF = 100000000;

        // multi source shortest path
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    // if we find that i->j via k is shortest then we update the matrix
                    if(dist[i][k] < INF && dist[k][j] < INF){
                        dist[i][j] = min(dist[i][j],
                                          dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }
};

int main() {
    Solution s;

    vector<vector<int>> dist = {
        {0, 4, 100000000, 5, 100000000},
        {100000000, 0, 1, 100000000, 6},
        {2, 100000000, 0, 3, 100000000},
        {100000000, 100000000, 1, 0, 2},
        {1, 100000000, 100000000, 4, 0}
    }; // 100000000 = it's nothing, just shows infinity, in GFG we have given infinity as 10^8

    s.floydWarshall(dist);
    for(auto row : dist){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
