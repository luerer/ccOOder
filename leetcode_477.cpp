/************
Total Hamming Distance
大意：
数组中所有汉明距离的和。
思路：
O(n^2):遍历每一对，计算汉明距离求和
O(n): 统计0-31 每一位上1出现的次数cnt,因此0出现(size-cnt)次，因此这一位对汉明距离贡献cnt*(size-cnt)
************/
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int size = nums.size();
        vector<int> cnt(32,0);
        int res=0;
    
        for(int i=0; i<32; ++i)
        {
            for(auto num:nums)
            {
                if((num>>i)&0x1) cnt[i]++;
            }
            res+=cnt[i]*(size-cnt[i]);
        }
        return res;
    }
};