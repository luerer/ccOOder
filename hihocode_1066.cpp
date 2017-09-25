/************
并查集 1066
************/
#include <bits/stdc++.h>
using namespace std;

int tot = 0;
const int maxn = 1e6+5;
int father[maxn];
unordered_map<string,int> name;
void init(){
	name.clear();
	for(int i=0; i<maxn; i++)
		father[i] = i;
	tot = 0;
}
int _hash(string s){
	if(name.find(s)!=name.end())
		return name[s];
	name[s] = tot++;
	return name[s];
}
int _find(int x){
	if(x==father[x]) return father[x];
	father[x] = _find(father[x]);
	return father[x];
}
void _union(int x, int y){
	int xx = _find(x);
	int yy = _find(y);
	if(xx!=yy) father[xx]=yy;
}
void solve(){
	int op;
	string a,b;
	cin>>op>>a>>b;
	int hasha, hashb;
	hasha = _hash(a);
	hashb = _hash(b);
	if(op){
		if(_find(hasha)==_find(hashb))
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}else{
		_union(hasha,hashb);
	}

}
int main(){
	init();
	int N;
	cin>>N;
	while(N--){
		solve();
	}
	return 0;
}