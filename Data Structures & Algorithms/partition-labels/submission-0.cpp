class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26);
        // Find the last occurance of each charecter
        for(int i = 0; i < s.length(); i++) last[s[i] - 'a'] = i;

        vector<int> res;
        int start = 0, end = 0;    // Start and End points of current partition

        for(int i = 0; i < s.length(); i++){
            end = max(end, last[s[i] - 'a']);

            // After reaching current partitions end
            if(i == end){
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return res;
    }
};
