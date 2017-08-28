fq2xmd
https://360.acmcoder.com/cand/index?.r=0.15125127150501627&#/main/rules

#include <bits/stdc++.h>
using namespace std;
bool camp(pair<int,int>& a, pair<int,int>& b){
	return a.second==b.second?a.first<b.first:a.second>b.second;
}
int main(){
	int n,tmp;
	cin>>n;
	vector<pair<int,int>> grades;
	vector<int> res(n,0);
	for(int i=0; i<n; i++){
		cin>>tmp;
		grades.push_back({i,tmp});
	}
	sort(grades.begin(),grades.end(),camp);
	int cnt = 0;
	for(auto g:grades){
		res[g.first] = min(cnt,g.first);
		cnt++;
	}

	
	for(int i=0; i<n-1; i++){
		cout<<res[i]<<" ";
	}
    cout<<res[n-1]<<endl;
	return 0;
}