/************
Validate Binary Search Tree
大意：
验证是否有效的二叉搜索树
思路：
递归，一般二叉搜索树 维护 MIN 和 MAX 两个值在每次递归中比较 （就是对每一个左子树中的值 需要和 MAX比较，必须小于MAX， 右子树同理） 
************/

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root,NULL,NULL);
    }
    bool validate(TreeNode* node, TreeNode* minNode, TreeNode* maxNode) {
        if(node == NULL) return true;
        if(minNode && node->val<=minNode->val || maxNode && node->val >= maxNode->val) return false;
        return validate(node->left,minNode,node) && validate(node->right,node,maxNode);
        
    }
};

/************
大神还是多，根据递归的性质，先左再右，层层回溯，只要维护一个prev节点，左子树有效的情况下，右子树和prev比 都大于他，也有效。

这里用到了 指针的引用 注意理解。 *& *的优先级高，这句话表示prev是个指针，然后取了引用。 注意和**区别。
************/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    bool validate(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right, prev);
    }
};