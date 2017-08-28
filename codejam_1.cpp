#include <bits/stdc++.h>
using namespace std;
int res = INT_MAX;
void slove(string& s, int pos, int cnt, string board){
    if(pos == s.size()){
        res = min(res,cnt);
        return;
    }
    if(cnt>=res) return;
    for(int i=1; i<=s.size()-pos; i++){
        string tmp = s.substr(pos,i);
        int p1 = s.substr(0,pos).find(tmp);
        if(p1<pos && p1!=string::npos){
            if(board!=tmp){
                slove(s,pos+i,cnt+2,tmp);
                slove(s,pos+i,cnt+i,board);
            }
            else slove(s,pos+i,cnt+1,tmp);
        }else{
            slove(s,pos+i,cnt+i,board);
        }
    }
}

int main(){
    ifstream in("/Users/luerer/Downloads/A-small-attempt2.in", ios::in);
    ofstream out("/Users/luerer/Downloads/A-small-attempt2.out", ios::out);
    int n;
    in>>n;
    for(int i=1; i<=n; i++){
        string s;
        in>>s;
        res = INT_MAX;
        slove(s,0,0,"");
        out<<"Case #"<<i<<": "<<res<<endl;
    }
    return 0;
}