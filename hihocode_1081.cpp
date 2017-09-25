/************
1081 最短路径 一 （Dijkstra 迪杰斯特拉）
输入

每个测试点（输入文件）有且仅有一组测试数据。

在一组测试数据中：

第1行为4个整数N、M、S、T，分别表示鬼屋中地点的个数和道路的条数，入口（也是一个地点）的编号，出口（同样也是一个地点）的编号。

接下来的M行，每行描述一条道路：其中的第i行为三个整数u_i, v_i, length_i，表明在编号为u_i的地点和编号为v_i的地点之间有一条长度为length_i的道路。

对于100%的数据，满足N<=10^3，M<=10^4, 1 <= length_i <= 10^3, 1 <= S, T <= N, 且S不等于T。

对于100%的数据，满足小Hi和小Ho总是有办法从入口通过地图上标注出来的道路到达出口。

输出

对于每组测试数据，输出一个整数Ans，表示那么小Hi和小Ho为了走出鬼屋至少要走的路程。

样例输入
5 23 5 4
1 2 708
2 3 112
3 4 721
4 5 339
5 4 960
1 5 849
2 5 98
1 4 99
2 4 25
2 1 200
3 1 146
3 2 106
1 4 860
4 1 795
5 4 479
5 4 280
3 4 341
1 4 622
4 2 362
2 3 415
4 1 904
2 1 716
2 5 575
样例输出
123
************/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3+5;
vector<int> g[maxn];
vector<bool> vis(maxn);
vector<int> dis(maxn);

void init(){
	for(int i=0; i<maxn; ++i){
		vis[i] = false;
		g[i].resize(maxn,INT_MAX);
	}

}
void solve(int n, int m, int s, int t){
	for(int i=1; i<=n; ++i)
		dis[i] = g[s][i];
	dis[s] = 0;
	vis[s] = true;

	for(int i=1; i<=n; ++i){
		int min_len = INT_MAX;
		int u = s;
		for(int j=1; j<=n; ++j){
			if(!vis[j] && dis[j]<min_len){
				u = j;
				min_len = dis[j];
			}
		}
		vis[u] = true;
		for(int j=1; j<=n; ++j){
			if(!vis[j] && g[u][j]<INT_MAX){
				dis[j] = min(dis[j],dis[u]+g[u][j]);
			}
		}
	}
	cout<<dis[t]<<endl;
}
int main(){
	int n,m,s,t;
	cin>>n>>m>>s>>t;
	init();
	int u,v,len;
	for(int i=1; i<=m; ++i){
		cin>>u>>v>>len;
		g[u][v]=g[v][u] = min(len,g[u][v]);
	}
	solve(n,m,s,t);
	return 0;
}