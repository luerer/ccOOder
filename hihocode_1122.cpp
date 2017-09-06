/************
二分图二•二分图最大匹配之匈牙利算法
大意：
二分图中找到最大的匹配的对数。
输入
第1行：2个正整数，N,M(N表示点数 2≤N≤1,000，M表示边数1≤M≤5,000)
第2..M+1行：每行两个整数u,v，表示一条无向边(u,v)

输出
第1行：1个整数，表示最大匹配数

样例输入
5 4
3 2
1 3
5 4
1 5
样例输出
2
************/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> G;
vector<int> vis;
vector<int> link;
bool dfs(int v){
    for(int i=0; i<G[v].size(); ++i){
        int u = G[v][i];
        if(vis[u]==0){
            vis[u] = 1;
            if(link[u]==0 || dfs(link[u])){
                link[u] = v;
                link[v] = u;
                return true;
            }
        }
    }
    return false;
}
int main(){
    int n,m,a,b;
    while(cin>>n>>m){
        G.resize(n+1);
        link.resize(n+1);
        while(m--){
            cin>>a>>b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        int cnt = 0;
        for(int i=1; i<=n; ++i){
            if(link[i]==0){
                vis=vector<int>(n+1,0);
                if(dfs(i)) cnt++;
            }
        }
        cout<<cnt<<endl;
    }

}