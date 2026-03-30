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
    int checkGood(TreeNode* root, int maxSo){
        if(root == nullptr) return 0;
        int count = 0;
        if(root -> val >= maxSo) count = 1;
        maxSo = max(maxSo, root -> val);
        count += checkGood(root -> left, maxSo);
        count += checkGood(root -> right, maxSo);
        return count;
    }

    int goodNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        return checkGood(root, root -> val);
    }
};
