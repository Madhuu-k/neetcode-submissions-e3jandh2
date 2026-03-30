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
    unordered_map<int, int> inorderIndex;
    int preIndx = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++) inorderIndex[inorder[i]] = i;
        return Build(preorder, 0, inorder.size() - 1);
    }

    TreeNode* Build(vector<int>& preorder, int inStart, int inEnd){
        if(inStart > inEnd) return nullptr;
        
        int rootVal = preorder[preIndx++];
        TreeNode* root = new TreeNode(rootVal);
        
        int mid = inorderIndex[rootVal];

        root -> left = Build(preorder, inStart, mid - 1);
        root -> right = Build(preorder, mid + 1, inEnd);

        return root;
    }
};
