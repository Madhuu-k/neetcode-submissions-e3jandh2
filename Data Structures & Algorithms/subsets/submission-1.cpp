class Solution {
public:
    vector<int> temp;
    void backtrack(vector<vector<int>>& res, vector<int>& nums, int start){
        res.push_back(temp);
        for(int i = start; i < nums.size(); i++){
            temp.push_back(nums[i]);
            backtrack(res, nums, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(res, nums, 0);
        return res;
    }
};