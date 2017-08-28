/************
Kth Smallest Number in Multiplication Table
大意：
找到乘法表中 第k大的数字。
乘法表： 表中元素nums[i][j] = i*j (1<=i<=m, 1<=j<=n)
思路：
二分。
二分的判断条件是，表中 小于或等于 当前值的元素个数。
************/
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m*n;
        while(l<r){
            int mid = l + (r-l)/2;
            int cnt = count(mid,m,n);
        
            if(count(mid,m,n)>=k)//由于统计的是小于等于的个数，
                r = mid;         //因此此条件中可能包含最终值。
            else 
                l = mid+1;
        }
        return r;
    }
    int count(int t, int m, int n){
        int cnt = 0;
        for(int i=1; i<=m; i++){
            cnt += min(t/i,n);
        }
        return cnt;
    }
    
};