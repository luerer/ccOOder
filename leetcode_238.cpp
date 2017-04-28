/************
Product of Array Except Self
大意：
返回这个一个数组res，其中res[i]为原数组中除了nums[i]的其他所有数的乘积。
思路：
题目要求不能用除法，且O(N)，最好O(1)空间。
开始想到两个数组分别存当前数字左边部分和右边部分的乘积，为了O(1)空间，可以优化。

res中直接存左边的乘积，右边的乘积用变量。
************/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(),1);
        for(int i=1; i<nums.size(); ++i)
        {
            res[i] = res[i-1]*nums[i-1];
        }
        int right = 1;
        for(int i=nums.size()-2; i>=0; --i)
        {
            right *= nums[i+1];
            res[i] *= right;
        }
        return res;
    }
};