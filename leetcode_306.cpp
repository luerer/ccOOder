/************
Additive Number
大意：
给一个字符串，判断是否是一个斐波那契数列。
如
112358 ==> 1, 1, 2, 3, 5, 8 true
199100199 ==> 1, 99, 100, 199 true
111 false
思路：
肯定是递归。关键是第一个和第二个数的选择。遍历第一个和第二个数的所有选择递归判断。
注意边界条件。

递归： 1.划分子问题 2.退出递归的状态

************/
class Solution {
public:
    string add(string& a, string& b){
        string res;
        int i = a.size()-1, j = b.size()-1;
        int carry = 0;
        while(i>=0 || j>=0){
            int sum = carry+(i>=0?(a[i--]-'0'):0) + (j>=0?(b[j--]-'0'):0);
            res.push_back(sum%10 + '0');
            carry = sum/10;
        }
        if(carry) res.push_back(carry+'0');
        reverse(res.begin(),res.end());
        return res;
    }
    bool isvalid(string num1, string num2, string num){
        if(num1.size()>1&&num1[0]=='0' || num2.size()>1&&num2[0]=='0') return false;
        string sum = add(num1,num2);
        if(num==sum) return true;
        if(num.size()<=sum.size()) return false;
        else return isvalid(num2,sum,num.substr(sum.size()));
    }
    bool isAdditiveNumber(string num) {
        if(num.size()<3) return false;
        for(int i=1; i<=num.size()/2; i++){
            for(int j=1; j<=(num.size()-i)/2; j++){
                if(isvalid(num.substr(0,i),num.substr(i,j),num.substr(i+j)))
                    return true;
            }
            
        }
        return false;
    }
};