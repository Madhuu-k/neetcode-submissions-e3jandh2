class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for(auto it : intervals){
            if(res.empty()){
                res.push_back(it);
                continue;
            }
            vector<int> last = res.back();
            if(!res.empty() && last[1] >= it[0]){
                res.back()[1] = max(last[1], it[1]);
            }

            else res.push_back(it);
        }

        return res;
    }
};
