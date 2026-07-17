class Solution {
public:
    vector<int> temp;

    void backtrack(vector<vector<int>>& res, vector<int>& nums, int target, int start){
        if(target == 0){ 
            res.push_back(temp);
            return;    
        }

        if(target < 0 || start == nums.size()) return;

        temp.push_back(nums[start]);
        backtrack(res, nums, target - nums[start], start);
        temp.pop_back();
        backtrack(res, nums, target, start + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        backtrack(res, nums, target, 0);
        return res;
    }
};
