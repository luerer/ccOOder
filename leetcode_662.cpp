/************
Maximum Width of Binary Tree
大意：
求一棵树中，最宽的那一层的宽度。
Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
起始 和 结束 节点之间的宽度（包括中间的NULL）。
思路：
深搜，利用dfs的特性 和 用数组存节点的特性。
1.每一层最左边的叶子肯定是最先被遍历到的。
2.节点 i 的左儿子一定在 2i 位置，右儿子一定在 2i+1。
对每一层，更新最右儿子的位置就可以了。
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
class Solution {
private:
    vector<pair<int,int>> nodes;
public:
    int dfs(TreeNode* root, int level, int order){
        if(!root) return 0;

        if(level==nodes.size()) nodes.push_back(make_pair(order,order));
        else nodes[level].second = order;
        
        int left = dfs(root->left,level+1,2*order);
        int right = dfs(root->right,level+1,2*order+1);
        int w = nodes[level].second-nodes[level].first+1;
        return max(w,max(left,right));
    }
    int widthOfBinaryTree(TreeNode* root) {
        return dfs(root,0,1);
    }
};