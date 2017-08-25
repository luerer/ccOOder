#include <bits/stdc++.h>
using namespace std;

string dictStr = "n/a";
int min_cnt = INT_MAX;

void dfs(const string& s, string cur, const set<string>& dict, int pos, int cnt){
    if(pos==s.size() && cnt<min_cnt) {
        dictStr = cur;
        min_cnt = min(min_cnt,cnt);
    }

    else{
        for(int l=1; l<=s.size(); l++){
            if(pos+l-1>=s.size()) break;
            string tmp = s.substr(pos,l);
            if(dict.find(tmp)==dict.end()) continue;
            string cur_tmp = cur+' '+tmp;
            dfs(s,cur_tmp,dict,pos+l,cnt+1);
        }
    }
}

void mincut(const string& str, const set<string>& dict)
{
    for(int l=1; l<=str.size(); l++){
        if(l-1>=str.size()) break;
        string tmp = str.substr(0,l);
        if(dict.find(tmp)==dict.end()) continue;
        dfs(str,tmp,dict,l,0);
    }

}


int main(int argc, const char * argv[])
{
    string strS;
    int nDict;
    set<string> dict;

    cin>>strS;
    cin>>nDict;
    for (int i = 0; i < nDict; i++)
    {
        cin>>dictStr;
        dict.insert(dictStr);
    }
    dictStr = "n/a";
    mincut(strS, dict);
    cout<<dictStr<<endl;
    return 0;
}