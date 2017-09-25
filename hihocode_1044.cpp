/************
状态压缩·一
大意：
小Hi和小Ho所处的车厢可以被抽象成连成一列的N个位置，按顺序分别编号为1..N，每个位置上都有且仅有一名乘客在休息。
同时每个位置上都有一些垃圾需要被清理，其中第i个位置的垃圾数量为Wi。乘务员可以选择其中一些位置进行清理，但是值得注意的是，
一旦有编号连续的M个位置中有超过Q个的位置都在这一次清理中被选中的话（即这M个位置上的乘客有至少Q+1个被惊醒了），
就会发生令人不愉快的口角。而小Hi和小Ho的任务是，计算选择哪些位置进行清理，在不发生口角的情况下，清扫尽可能多的垃圾。

输入

每个测试点（输入文件）有且仅有一组测试数据。

每组测试数据的第一行为三个正整数N、M和Q，意义如前文所述。

每组测试数据的第二行为N个整数，分别为W1到WN，代表每一个位置上的垃圾数目。

对于100%的数据，满足N<=1000, 2<=M<=10,1<=Q<=M, Wi<=100

输出

对于每组测试数据，输出一个整数Ans，表示在不发生口角的情况下，乘务员最多可以清扫的垃圾数目。

样例输入
5 2 1
36 9 80 69 85 
样例输出
201
************/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
vector<int> w;
int sum(int n){
    int cnt = 0;
    while(n){
        cnt += n&1;
        n>>=1;
    }
    return cnt;
}
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    w.resize(n,0);
    dp.resize(n+1,vector<int>(1<<m,0));
    for(int i=0; i<n; i++) cin>>w[i];
    
    for(int i=1; i<=n; i++){
        for(int j=0; j<(1<<min(i,m)); j++){
            if(sum(j)>q) continue;
            if(j&1)
                dp[i][j] = max(dp[i-1][j>>1],dp[i-1][(j>>1)|(1<<m-1)])+w[i-1];
            else
                dp[i][j] = max(dp[i-1][j>>1],dp[i-1][(j>>1)|(1<<m-1)]);
        }
    }
    int ans = 0;
    for(auto i:dp)
        for(auto j:i)
            ans = max(ans,j);
    cout<<ans<<endl;
    return 0;
}