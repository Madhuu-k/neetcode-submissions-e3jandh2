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
    int goodCount = 0;

    void checkGood(TreeNode* root, int rootVal){
        if(!root) return;
        if(root -> val >= rootVal) goodCount++;
        rootVal = max(rootVal, root -> val);
        checkGood(root -> left, rootVal);
        checkGood(root -> right, rootVal);
    }

    int goodNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        checkGood(root, root -> val);
        return goodCount;
    }
};
