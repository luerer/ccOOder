/************
Delete Node in a BST
大意：
找到二叉查找树中的特定节点，并删除。（当然删除后要调整节点）
思路：
递归
当根结点是需要查找的节点时：
1 如果没有右子树，直接让左子树替代他的位置。
2 如果有右子树，让右子树最左节点的值替代他的值。（不用删除最左节点，因为最后还会回归到情景1）
如果跟节点不是要查找的值，分别对左右节点递归查找删除。
************/
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val == key){
            if(!root->right) return root->left;
            else{
                TreeNode* right = root->right;
                while(right->left)
                    right = right->left;
                swap(root->val,right->val);    
            }
        }
        root->left = deleteNode(root->left,key);
        root->right = deleteNode(root->right,key);
        return root;
    }
};