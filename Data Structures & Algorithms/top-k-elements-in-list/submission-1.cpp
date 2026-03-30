class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int x : nums) freq[x]++;
        vector<pair<int, int>> pairs;
        for(auto it : freq) pairs.push_back({it.second, it.first});
        vector<int> rs;
        sort(pairs.begin(), pairs.end(), greater<>());
        for(int i = 0; i < k; i++) rs.push_back(pairs[i].second);
        return rs;
    }
};
