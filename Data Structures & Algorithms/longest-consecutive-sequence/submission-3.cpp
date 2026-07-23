class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int maxLen = 0;
        for(int num : nums){
            if(!seen.count(num - 1)){
                int len = 1;
                int curr = num;

                while(seen.count(curr + 1)){
                    len++;
                    curr++;
                }

                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};
