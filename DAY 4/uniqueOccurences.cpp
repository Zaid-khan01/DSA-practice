class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map <int, int> mp;
        for(int num:arr){
            mp[num]++;
        }
        // now, check the count and insert it in set
        unordered_set<int> set;
        for(auto it:mp){
            int count = it.second;
            set.insert(count);
        }
        return mp.size() == set.size();
    }
};