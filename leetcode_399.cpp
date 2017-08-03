/************
Evaluate Division
大意：
根据给定的除法，得到新的表达式的值
Given a / b = 2.0, b / c = 3.0. 
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
return [6.0, 0.5, -1.0, 1.0, -1.0 ].
思路：
这题是第一次接触图。用带权重的图很容易做，稍微修改一下Floyd算法。
************/
class Solution {   
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> res;
        unordered_map<string,unordered_map<string,double>> hash;
        for(int i=0; i<equations.size(); i++){
            hash[equations[i].first][equations[i].second] = values[i];
            hash[equations[i].second][equations[i].first] = 1/values[i];
            hash[equations[i].first][equations[i].first] = 1.0;
            hash[equations[i].second][equations[i].second] = 1.0;
        }
        
        for(auto k:hash){
            for(auto x:hash){
                for(auto y:hash){
                    if(hash[x.first].find(y.first)!=hash[x.first].end()) continue;
                    if(hash[x.first].find(k.first)!=hash[x.first].end() && hash[k.first].find(y.first)!=hash[k.first].end())
                        hash[x.first][y.first] = hash[x.first][k.first]*hash[k.first][y.first];
                }
            }
        }
        for(auto it:queries){
            if(hash[it.first].find(it.second)!=hash[it.first].end())
                res.push_back(hash[it.first][it.second]);
            else res.push_back(-1.0);
        }
        return res;
    }
};