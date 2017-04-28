/************
Friend Circles
大意：
找朋友，有直接关系的为1，如果M(i,j)=1 && M(j,k)=1,那么ijk属于一个朋友圈。
思路：
新知识-并查集，解决是否属于同一个集合的问题，最后计数集合数，具体见笔记。

************/
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        friends.resize(M.size(),0);
        for(int i=0; i<M.size(); ++i)
            friends[i] = i;
        for(int i = 0; i<M.size(); ++i)
        {
            for(int j=0; j<i; ++j)
            {
                if(M[i][j]) _union(i,j);
            }
        }
        int node=0;
        for(int i=0; i<friends.size(); ++i)
        {
            if(i==friends[i]) node++;
        }
        return node;
    }
private:
    vector<int> friends;
    int find(int x)
    {
        if(x==friends[x]) return x;
        return friends[x]=find(friends[x]);
    }
    
    int _union(int x, int y)
    {
        int rx = find(x);
        int ry = find(y);
        if(rx==ry) return rx;
        friends[rx] = ry;
        return ry;
    }
};