/************
Spiral Matrix II
大意：
螺旋遍历矩阵
思路：
4个变量，维护每行和每列的 起始 和 结束 位置

方法二：用一个方向数组，每次换方向。详细见54题。
************/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        int a=0, b=0, c=n-1, d=n-1;
        int i=1;
        while(1){
            for(int y=b; y<=d; y++) res[a][y]=i++;
            if(++a > c) break;
            
            for(int x=a; x<=c; x++) res[x][d]=i++;
            if(--d < b) break;
            
            for(int y=d; y>=b; y--) res[c][y]=i++;
            if(--c < a) break;
            
            for(int x=c; x>=a; x--) res[x][b]=i++;
            if(++b > d) break;
        }
        return res;
    }
};