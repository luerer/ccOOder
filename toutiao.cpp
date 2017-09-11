#include <bits/stdc++.h>
using namespace std;
int slove(vector<int>& num, int m){
	int res = 0;
	int len = 0;
	int l = 0, r = 0;
	int lm = 0, rm = 0;
	for(int i=0; i<num.size(); ++i){
		if(i<num.size()-1 && num[i]+1==num[i+1]) r++;
		else if(i!=num.size()-1) r++, l=r;

		if(r-l+1>len){
			len = r-l+1;
			lm = l, rm = r;
		}
	}

	for(int i=max(lm-1,0), j=min((int)num.size()-1,rm+1); i>=0 || j<num.size();){
		if(num[lm]-num[i] < num[j]-num[rm]) m-=(num[lm]-num[i]-1), i--,lm--;
		else m-=(num[j]-num[rm]-1), r++,rm++;
		if(m>=0) len++;
		else break;
	}
	return len;
	
}
int main(){
	string s;
	int m;
	cin>>s>>m;
	int res = 0;
	for(int i=0; i<s.size(); i++){

	}
	map<char,vector<int>> alp;
	for(int i=0; i<s.size(); ++i){
		alp[s[i]].push_back(i);
	}
	for(auto aa:alp){
		if(aa.second.size()<=res) continue;
		res = max(res,slove(aa.second,m));
	}
	cout<<res<<endl;
}