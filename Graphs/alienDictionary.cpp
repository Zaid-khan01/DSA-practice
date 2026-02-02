#include <bits/stdc++.h>
using namespace std;

class Solution {
private: 
    vector<int> topoSort(int K, vector<vector<int>>& adj) {
    vector<int> indegree(K, 0);
    
    for(int i = 0; i < K; i++) {
        for(auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i = 0; i < K; i++) {
        if(indegree[i] == 0)
            q.push(i);
    }

    vector<int> topo;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto it : adj[node]) {
            indegree[it]--;
            if(indegree[it] == 0)
                q.push(it);
        }
    }

    return topo;
}

  public:
     string findOrder(vector<string> &words) {
        int N = words.size();

        // Step 1: map characters to integers
        unordered_map<char, int> mp;
        int idx = 0;
        for(auto &w : words) {
            for(char c : w) {
                if(mp.find(c) == mp.end())
                    mp[c] = idx++;
            }
        }

        int K = idx;
        vector<vector<int>> adj(K);

        // Step 2: build graph
        for(int i = 0; i < N - 1; i++) {
            string &s1 = words[i];
            string &s2 = words[i + 1];
            int len = min(s1.size(), s2.size());
            bool found = false;

            for(int j = 0; j < len; j++) {
                if(s1[j] != s2[j]) {
                    adj[mp[s1[j]]].push_back(mp[s2[j]]);
                    found = true;
                    break;
                }
            }

            // prefix invalid case
            if(!found && s1.size() > s2.size())
                return "";
        }

        // Step 3: call topo
        vector<int> topo = topoSort(K, adj);

        // cycle check
        if(topo.size() < K)
            return "";

        // Step 4: reverse map
        vector<char> rev(K);
        for(auto it : mp)
            rev[it.second] = it.first;

        // Step 5: convert topo → string
        string ans = "";
        for(int x : topo)
            ans += rev[x];

        return ans;
    }
};

int main() {
    Solution s;
    vector<string> words = {"baa", "abcd", "abca", "cab", "cad"};

    string order = s.findOrder(words);

    if(order == "")
        cout << "Invalid ordering\n";
    else
        cout << "Alien Order: " << order << endl;

    return 0;
}