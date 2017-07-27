/************
Simplify Path
大意：
简化路径 如path = "/a/./b/../../c/", => "/c"
思路：
stringstream 按'/'分割村粗 如果..则pop
注意边界情况
************/

class Solution {
public:
    string simplifyPath(string path) {
        string res, tmp;
        vector<string> p;
        stringstream ss(path);
        while(getline(ss,tmp,'/')){
            if(tmp=="" || tmp==".") continue;
            if(tmp==".." && !p.empty()) p.pop_back();
            else if(tmp!="..") p.push_back(tmp);
        }
        for(auto pp:p) res+="/"+pp;
        return res.empty()?"/":res;
    }
};