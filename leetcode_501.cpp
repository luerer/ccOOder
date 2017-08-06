/************
Find Mode in Binary Search Tree
大意：
找出一个二叉搜索树中出现次数最多的节点值
思路：
灵活运用中序遍历的特点。
中序遍历的结果肯定是递增的 一样的节点肯定在遍历过程中是相邻的。
中序遍历不管怎么遍历，掌握节点的遍历顺序！！！！这点很重要。
************/
class Solution {
    vector<int> res;
    int curmax = 0;
    int cur;
    int curcnt = 0;
public:
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        curcnt++;
        if(cur!=root->val){
            curcnt = 1;
            cur = root->val;
        }
        if(curcnt>curmax){
            curmax = curcnt;
            res.clear();
            res.push_back(root->val);
        }else if(curcnt==curmax){
            res.push_back(root->val);
        }
        
        dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        int cnt = 0;
        dfs(root);
        return res;
    }
};