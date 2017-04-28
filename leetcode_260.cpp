/************
Single Number (3)
大意：
一组数字，其中两个出现一次，其余出现两次，找出出现一次的两个数字。
思路：
根据之前只出现一次的题目（异或），将整组数字分为两组，每组(2*n+1).
根据两个数异或的最后一个'1'位分组。

************/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int twonum = 0;
        for(auto i:nums) twonum^=i;
        int lastbit = (twonum&(twonum-1))^twonum;
        
        int A=0,B=0;
        for(auto i:nums)
        {
            if(i&lastbit) A^=i;
            else B^=i;
        }
        return vector<int>{A,B};
        
    }
    
};