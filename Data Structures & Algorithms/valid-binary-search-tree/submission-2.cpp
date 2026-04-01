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
    bool isValidBST(TreeNode* root, int minVal, int maxVal){
        if(root == nullptr) return true;
        // Check if nodes value is within the range
        if(root -> val <= minVal || root -> val >= maxVal) return false;

        return isValidBST(root -> left, minVal, root -> val) &&
               isValidBST(root -> right, root -> val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return isValidBST(root, INT_MIN, INT_MAX);
    }
};
