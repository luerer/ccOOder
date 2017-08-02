/************
Maximum XOR of Two Numbers in an Array
大意：
找到一个数组中，两两异或的最大值。
思路：
根据异或的性质，显然用字典树。
************/

class Solution {
private:
    typedef struct TreeNode
    {
        TreeNode* next[2];
        TreeNode(){next[0]=NULL; next[1]=NULL;}
    }TreeNode;
public:
    int findMaximumXOR(vector<int>& nums) {
        TreeNode *root = settree(nums);
        int res = INT_MIN;
        for(auto num:nums)
        {
            res = max(res,search(root,num));
        }
        return res;
    }
    
    TreeNode* settree(vector<int> &nums)
    {
        TreeNode *root = new TreeNode();
        TreeNode *cur = root;
        for(auto num:nums)
        {
            cur = root;
            for(int i=31; i>=0; i--)
            {
                if((num>>i)&1)
                {
                    if(cur->next[1]==NULL) cur->next[1] = new TreeNode();
                    cur = cur->next[1];
                    
                }
                else
                {
                    if(cur->next[0]==NULL) cur->next[0] = new TreeNode();
                    cur = cur->next[0];
                }
                
            }
        }
        return root;
    }
    
    int search(TreeNode *cur, int num)
    {
        int res=0;
        for(int i=31; i>=0; i--)
        {
            int flag = (num>>i)&1;
            if(cur->next[1-flag]) 
            {
                res<<=1;
                res|=1;
                cur = cur->next[1-flag];
            }else{
                res<<=1;
                res|=0;
                cur = cur->next[flag];
            }
            
        }
        return res;
    }
};