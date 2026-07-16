class Solution {
public:
    vector<int> temp;

    void backtrack(vector<vector<int>>& res, vector<int>& candidates, int target, int start){
        if(target == 0) {
            res.push_back(temp);
            return;    
        }
        if(target < 0 || start == candidates.size()) return;

        temp.push_back(candidates[start]);
        backtrack(res, candidates, target - candidates[start], start);

        temp.pop_back();
        backtrack(res, candidates, target, start + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        backtrack(res, candidates, target, 0);
        return res;
    }
};