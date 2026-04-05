class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, maxLen = INT_MIN;
        unordered_map<char, int> seen;

        for(int right = 0; right < s.length(); right++){
            seen[s[right]]++;
            while(seen[s[right]] > 1){
                seen[s[left]]--;
                if(seen[s[left]] == 0) seen.erase(s[left]);
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen == INT_MIN ? 0 : maxLen;
    }
};
