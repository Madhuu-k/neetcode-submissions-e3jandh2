class Solution {
public:
    vector<int> temp;

    void backtrack(vector<vector<int>>& res, vector<int>& nums, int target, int start){
        if(target == 0){
            res.push_back(temp);
            return;
        }

        for(int i = start; i < nums.size(); i++){
            if(i > start && nums[i] == nums[i - 1]) continue;
            if(nums[i] > target) break;
            temp.push_back(nums[i]);
            backtrack(res, nums, target - nums[i], i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        backtrack(res, nums, target, 0);
        return res;
    }
};
