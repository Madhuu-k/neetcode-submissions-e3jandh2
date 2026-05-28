class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, maxLen = 0;
        unordered_map<char, int> freq;

        for(int right = 0; right < s.length(); right++){
            freq[s[right]]++;
            while(freq[s[right]] > 1){
                freq[s[left]]--;
                if(freq[s[left]] == 0) freq.erase(s[left]);
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};
