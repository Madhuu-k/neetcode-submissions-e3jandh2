class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        
        for(auto it : intervals){
            if(res.empty()){
                res.push_back(it);
                continue; // Skip it = 0
            }

            vector<int> lastInterval = res.back();
            // If Current Start Time is Less Than last Interval End Time
            if(it[0] <= lastInterval[1]){ 
                res.back()[1] = max(lastInterval[1], it[1]);
            }
            else res.push_back(it);
        }

        return res;
    }
};
