class Solution {
public:
    vector<int> temp;
    void backtrack(vector<vector<int>>& res, vector<int>& nums, int start){
        res.push_back(temp);
        sort(nums.begin(), nums.end());

        for(int i = start; i < nums.size(); i++){
            if(i > start && nums[i] == nums[i - 1]) continue;
            temp.push_back(nums[i]);
            backtrack(res, nums, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(res, nums, 0);
        return res;
    }
};
