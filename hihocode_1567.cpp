/************
偶树的切分
大意：
如果一棵树节点数目是偶数，那么就称这棵树是偶树。给定一棵N个节点的偶树(编号1~N)，小Hi想知道他最多可以同时切断多少条边，使得剩下的森林中每一个联通分量都是一棵偶树。

例如如下的偶树：

      1   
   / | | \
  2  3 4  5
  |
  6
可以切断1-2之间边使得剩下的每个联通分量都是偶树。

输入
第一行包含一个偶数N。  

以下N-1行每行包含两个整数a和b，表示a和b之间有一条边。  

对于30%的数据，1 ≤ N ≤ 20  

对于100%的数据， 1 ≤ N ≤ 100000

输出
输出最多可以切断的边数。

样例输入
6  
1 2  
3 1  
4 1  
1 5  
6 2
样例输出
1

邻接表 存储图的结构。然后深搜。
************/

#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
int dfs(vector<int>* node, int root, int par){//par: 父节点
    int res = 1;
    for(auto son:node[root]){
        if(son==par) continue;
        int tmp = dfs(node,son,root);
        if(tmp>0 && tmp%2==0) cnt++;
        res+=tmp;
    }
    return res;
}
int main(){
    int n,x,y;
    cin>>n;
    vector<int> node[n+1];
    while(cin>>x>>y){
        node[x].push_back(y);
        node[y].push_back(x);
    }
    dfs(node,1,0);
    cout<<cnt<<endl;
}