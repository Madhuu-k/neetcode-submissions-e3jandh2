class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> freq;
        for(int x : nums){
            if(freq.count(x)) return true;
            freq.insert(x);
        }
        return false;
    }
};