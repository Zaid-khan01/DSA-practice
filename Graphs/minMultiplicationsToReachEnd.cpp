// using Dijkstra Algorithm we can solve this
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // edge case
        if(start == end) return 0;
        
        queue<pair<int, int>> q;
        q.push({start, 0});
        
        vector<int> dist(100000, INT_MAX);
        dist[start] = 0;
        
        int mod = 100000; // if node exceeds limit 10^5 then we apply mod with 10^5 
        
        while(!q.empty()){
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if(steps > dist[node]) continue;
            
            // dist or edge relaxation if steps + 1 < dist[num]
            for(auto it: arr){
                int num = (1LL * it * node) % mod;
                if(steps + 1 < dist[num]){
                    dist[num] = steps + 1;
                    if(num == end) return steps + 1; // we reached to end
                    q.push({num, steps + 1});
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> arr = {2, 5, 7};
    int start = 3;
    int end = 30;

    int ans = s.minimumMultiplications(arr, start, end);

    cout << "Minimum multiplications required: " << ans << endl;

    return 0;
}
