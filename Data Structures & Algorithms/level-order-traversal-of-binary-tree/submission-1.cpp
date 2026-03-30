/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;  // Initialize dble vector array
        if(!root) return ans;

        queue<TreeNode*> q; // Queue to store pointers of TreeNode
        q.push(root);

        while(!q.empty()){
            vector<int> level; // To store level elements
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                TreeNode *node = q.front(); // get the current root or subroot
                q.pop(); // pop the root
                level.push_back(node -> val); // push its (root) value to level
                if(node -> left) q.push(node -> left); // check if the current root has left
                if(node -> right) q.push(node -> right); // check if it has right nodes
            } 
            ans.push_back(level); // add result to ans after every iteration
        }
        return ans;
    }
};
