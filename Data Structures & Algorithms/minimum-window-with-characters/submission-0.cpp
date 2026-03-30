class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for(char c : t) need[c]++;
        int left = 0, have = 0, start = 0, minLen = INT_MAX;
        int needSize = need.size();

        for(int right = 0; right < s.size(); right++){
            window[s[right]]++;
            
            if(need.count(s[right]) && window[s[right]] == need[s[right]]) have++;

            while(have == needSize){
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    start = left;
                }

                window[s[left]]--;
                if (need.count(s[left]) && window[s[left]] < need[s[left]]) have--;
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
