class Solution {
public:
    bool isPalindrome(string s) {
        string final;
        for(char &c : s){
            c = tolower(c);
            if(c == ' ') continue;
            if(ispunct(c)) continue;
            final.push_back(c);
        }
        int left = 0, right = final.size() - 1;
        while(left < right){
            if(final[left] != final[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
