class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int longest = 0;

        for(int num : set){
            if(!set.count(num - 1)){   // set dosent have num - 1
                int curr = num;
                int length = 1;

                while(set.count(curr + 1)){ // We have the next element
                    length++;
                    curr++;
                }           

                longest = max(longest, length);
            }
        }

        return longest;
    }
};
