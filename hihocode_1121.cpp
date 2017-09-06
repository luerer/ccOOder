/************
二分图一•二分图判定
大意：
无向图中，每条边的两个顶点颜色要不一样（二分图），判断是否是有效的二分图。

输入

第1行：1个正整数T(1≤T≤10)

接下来T组数据，每组数据按照以下格式给出：

第1行：2个正整数N,M(1≤N≤10,000，1≤M≤40,000)

第2..M+1行：每行两个整数u,v表示u和v之间有一条边

输出

第1..T行：第i行表示第i组数据是否有误。如果是正确的数据输出”Correct”，否则输出”Wrong”

样例输入
2
5 5
1 2
1 3
3 4
5 2
1 5
5 5
1 2
1 3
3 4
5 2
3 5
样例输出
Wrong
Correct
************/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> mapp;
vector<int> node;
bool dfs(int x){
    for(int i=0; i<mapp[x].size(); ++i){
        int y = mapp[x][i];
        if(node[y]==0){
            node[y] = -node[x];
            if(!dfs(y)) return false;
        }
        else if(node[y]==node[x]) return false;
    }
    return true;
}
bool solve(){
    int n,m;
    cin>>n>>m;
    int a,b;
    mapp.resize(n+1);
    node.resize(n+1);
    for(int i=0; i<m; i++){
        cin>>a>>b;
        mapp[a].push_back(b);
        mapp[b].push_back(a);
    }
    for(int i=1; i<=n; ++i){
        if(node[i]==0){
            node[i] = -1;
            if(!dfs(i)){
                return false;
            }
        }
    }
    return true;

}
int main(){
    int T;
    cin>>T;
    while(T--){
        mapp.clear();
        node.clear();
        if(solve()) cout<<"Correct"<<endl;
        else cout<<"Wrong"<<endl;
    }
}



