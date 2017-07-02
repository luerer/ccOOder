/************
Kth Smallest Element in a Sorted Matrix
大意：
返回一个矩阵中第K小的数。这个矩阵每行每列都是升序的。
matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
思路：
1.维护一个大根堆。
2.看到的一个方法：二分法，厉害了。精髓：分两边找，维护边界就行了。
************/
//二分法：
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int beg = matrix[0][0];
        int end = matrix[n-1][n-1];
        int mid = 0;
        while(beg<end){
            mid = (beg+end)>>1;
            int cnt = 0;
            for(int i=0; i<n; ++i){
                cnt+=(upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin());
            }
            if(cnt<k) beg = mid+1;
            else end = mid;
        }
        return beg;
        
    }
};
//大根堆方法：
class Solution {  
public:  
    int kthSmallest(vector<vector<int>>& matrix, int k) {  
        priority_queue<int> heap;  
        for(int i=0; i<matrix.size(); ++i) {  
            for(int j=0; j<matrix[0].size(); ++j) {  
                if(heap.size() < k) heap.push(matrix[i][j]);  
                else {  
                    if(heap.top() <= matrix[i][j]) break;  
                    else {  
                        heap.push(matrix[i][j]);  
                        heap.pop();  
                    }  
                }  
            }  
        }  
        return heap.top();  
    }  
};  