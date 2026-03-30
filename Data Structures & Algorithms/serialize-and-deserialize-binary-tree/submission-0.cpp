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

class Codec {
public:
    void serializeHelp(TreeNode* root, string &s){
        if(!root){
            s += "null,";
            return;
        }

        s += to_string(root -> val) + ",";
        serializeHelp(root -> left, s);
        serializeHelp(root -> right, s);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        serializeHelp(root, s);
        return s;
    }
    
    TreeNode* deserializeHelp(queue<string>& q){
        string val = q.front();
        q.pop();

        if(val == "null") return nullptr;

        TreeNode *root = new TreeNode(stoi(val));
        root -> left = deserializeHelp(q);
        root -> right = deserializeHelp(q);

        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string item;
        queue<string> q;

        while(getline(ss, item, ',')){
            if(item.size() > 0) q.push(item);
        }

        return deserializeHelp(q);
    }
};
