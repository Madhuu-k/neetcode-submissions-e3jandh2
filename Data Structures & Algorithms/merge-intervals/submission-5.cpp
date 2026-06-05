class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());

        for(auto it : intervals){
            if(res.empty()){
                res.push_back(it);
                continue;   // Skip i = 0 part
            }

            vector<int> lastInterval = res.back();
            if(it[0] <= lastInterval[1]){
                res.back()[1] = max(lastInterval[1], it[1]);
            }
            else res.push_back(it);
        }

        return res;
    }
};