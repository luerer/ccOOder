/************
Longest Repeating Character Replacement
大意：
数组中 可以把任何字符替换成任意字符，最多只允许替换K次，返回替换后连续相同字符最长的长度。
思路：
1.如果没有次数限制，如何将一个字符串以最少的替换步骤，变成全部一样？
字符串长度 - 出现次数最多的字符次数
2.加上K次限制，可以用滑动窗。如果窗的范围内 窗长-出现最多的次数 > K，减小滑动窗大小。并重新计算最大的次数。
************/

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> al(26,0);
        int i=0, j=0;
        int cnt = 0;
        int res = 0;
        for(int j=0; j<s.size(); j++){
            al[s[j]-'A']++;
            cnt = max(cnt,al[s[j]-'A']);
            while(j-i-cnt+1 > k){
                al[s[i]-'A']--;
                i++;
                for(auto tmp:al)
                    cnt = max(cnt,tmp);
            }
            res = max(res,j-i+1);
        }
        return res;
    }
};