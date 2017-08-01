/************
Serialize and Deserialize BST
大意：
把二叉搜索树序列化，还要能再变回来
思路：
首先肯定是先序遍历，比较好恢复，注意在每棵子树加标记。

本来我的想法是按照"(root.left.right)"这个格式来，但是恢复起来比较麻烦。

看到大神利用stringstream的性质（自动按 空格 分割)。要注意传stringstream时，要引用传递。
************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        if(!root) return " #";
        res += " "+to_string(root->val);
        return res+serialize(root->left)+serialize(root->right);
    }
    
    TreeNode* dfs(stringstream &ss){
        string val;
        ss>>val;
        if(val == "#") return NULL;
        TreeNode* root = new TreeNode(atoi(val.c_str()));
        root->left = dfs(ss);
        root->right = dfs(ss);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        TreeNode* root = dfs(ss);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));