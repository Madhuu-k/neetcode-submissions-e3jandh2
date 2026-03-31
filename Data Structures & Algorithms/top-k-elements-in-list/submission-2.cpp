class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int x : nums) freq[x]++; // count the frequecy of each element

        vector<pair<int, int>> pairs;
        for(auto it : freq) pairs.push_back({it.second, it.first});
        sort(pairs.begin(), pairs.end(), greater<>());

        vector<int> res;
        for(int i = 0; i < k; i++) res.push_back(pairs[i].second);

        return res;
    }
};
