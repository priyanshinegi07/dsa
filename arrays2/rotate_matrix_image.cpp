//brute force
//put all the elements at their required position
//ans[j][n-i-1] = arr[i][j]
//TC : O(n^2) SC : O(n^2)

// optimal
//1. transpose 2. Reverse every row
//TC : O(n^2) SC : O(1) in place algorithm 

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //get the transpose
        int n = matrix.size();
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n ; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //reverse every row in transposed matrix
        for(int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
}; 
