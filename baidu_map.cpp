#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> keyboard;
void init(){
	for(int i=2; i<=9; i++){
		keyboard.push_back(vector<char>());
	}
	keyboard[2] = {'A','B','C'};
	keyboard[3] = {'D','E','F'};
	keyboard[4] = {'G','H','I'};
	keyboard[5] = {'J','K','L'};
	keyboard[6] = {'M','N','O'};
	keyboard[7] = {'P','Q','R','S'};
	keyboard[8] = {'T','U','V'};
	keyboard[9] = {'W','X','Y','Z'};
}

void printv(vector<char>& tmp){
	for(int i=0; i<tmp.size();i++)
		cout<<tmp[i]<<(i==tmp.size()-1?endl:" ");
}

void findAll(vector<int>& nums, vector<char> tmp, int pos){
	if(pos == nums.size()){
		printv(tmp);
		return;
	}
	
	vector<char> cur = tmp;
	for(int j=0; j<keyboard[pos].size()){
		cur.push_back(keyboard[pos][j]);
		findAll(nums,cur,pos+1);
		cur.pop_back(keyboard[pos][j]);
	}
}

int main(){
	vector<int> nums;
	int n;
	while(cin>>n) nums.push_back(n);
	findAll(nums,vector<char>(),0);
	return 0;
}