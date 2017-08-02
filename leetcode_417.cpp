/************
Pacific Atlantic Water Flow
大意：
太平洋在上侧和左侧，大西洋在右侧和下侧。水往低处流，找到可以流进两个洋的坐标。
Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
思路：
反过来，从两个洋开始，按照往大于等于的方向搜。
两个洋都能到的点 是 两种方法搜索结果的交集。
************/
class Solution {
    //vector<vector<int>> dir = {{0,1},{-1,0},{1,0},{0,-1}};
    vector<pair<int, int>> result;
    vector<vector<int>> vis;
public:
    void dfs(int i, int j, vector<vector<int>>& matrix, int pre, int rc){
        int m = matrix.size();
        int n = matrix[0].size();
        if(i<0||i>=m || j<0||j>=n) return;
        if(matrix[i][j] < pre) return;//不能流动
        if((vis[i][j]&rc)==rc) return;//已经搜过
        vis[i][j] |= rc;
        if(vis[i][j]==3) result.push_back(make_pair(i,j));
        
        dfs(i+1,j,matrix,matrix[i][j],vis[i][j]);
        dfs(i,j+1,matrix,matrix[i][j],vis[i][j]);
        dfs(i-1,j,matrix,matrix[i][j],vis[i][j]);
        dfs(i,j-1,matrix,matrix[i][j],vis[i][j]);
    }
    
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty()) return result;
        int m = matrix.size();
        int n = matrix[0].size();
        vis.resize(m,vector<int>(n,0));
        for(int i=0; i<m; i++){
            dfs(i,0,matrix,INT_MIN,1);//1:从太平洋开始搜
            dfs(i,n-1,matrix,INT_MIN,2);//2:从大西洋开始搜
        }
        for(int j=0; j<n; j++){
            dfs(0,j,matrix,INT_MIN,1);
            dfs(m-1,j,matrix,INT_MIN,2);
        }
        return result;
    }
};