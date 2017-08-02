/************
Partition Equal Subset Sum
大意：
能否把数组分为两个和相等的子数组。
思路：
第一种方法就是普通的方法。
************/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return false;
        int target = sum>>1;
        vector<int> dp(target+1,0);//并不是dp，只是判断这个和能不能存在。
        dp[0]=1;
        for(int i=0;i<nums.size();++i)
        {
            for(int j = target; j>=nums[i]; --j)
            {
                dp[j]=dp[j]||dp[j-nums[i]];
            }
        }
        return dp[target];
    }
};
/************
第二种方法厉害了，用位运算。
************/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bitset<10001> bits(1);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (auto n : nums) bits |= bits << n;
        return !(sum & 1) && bits[sum >> 1];
    }
};