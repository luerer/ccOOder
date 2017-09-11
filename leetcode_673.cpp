/************
Number of Longest Increasing Subsequence
大意：
找到数组中最长的递增子序列 有多少个。
Example 1:
Input: [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:
Input: [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.

思路：
动规。
len[i]保存第i个数字结尾的最长子序列的长度。
cnt[i]保存第i个数字结尾的最长子序列的个数。
************/
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int s = nums.size();
        vector<int> len(s,1), cnt(s,1);//注意初始化。
        int maxlen = 1;
        for(int i=1; i<s; ++i){
            for(int j=0; j<i; ++j){
                if(nums[i]>nums[j]){
                    if(len[j]+1>len[i]){
                        len[i] = len[j]+1;
                        cnt[i] = cnt[j];
                    }else if(len[j]+1 == len[i]){
                        cnt[i] += cnt[j];
                    }
                }
                maxlen = max(maxlen,len[i]);
            }
        }
        int res = 0;
        for(int i=0; i<s; ++i){
            if(len[i]==maxlen) res+=cnt[i];
        }
        return res;
    }
};