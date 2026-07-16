class Solution {
public:
    vector<int> temp;
    
    void backtrack(vector<vector<int>>& res, vector<int>& nums, vector<bool>& visited){
        if(temp.size() == nums.size()){
            res.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(visited[i]) continue;
            visited[i] = true;

            temp.push_back(nums[i]);
            backtrack(res, nums, visited);
            temp.pop_back();

            visited[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> visited(nums.size(), false);
        backtrack(res, nums, visited);
        return res;
    }
};
