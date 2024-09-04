#include<iostream>
using namespace std;
//recursion to cal all paths
//we use dp to optimize
//TC : O(n*m) SC : O(n+m)
class Solution {
public:
    int f(int rows, int cols, int i, int j, vector<vector<int>>&dp) {
        //base case
        if(i >= rows or j >= cols) return 0;
        if(i == (rows-1) and j == (cols-1)) return 1;
        //recursive case
        if(dp[i][j] != -1) return dp[i][j];
        int right_paths = f(rows, cols, i, j+1, dp);
        int down_paths = f(rows, cols, i+1, j, dp);
        return dp[i][j] = right_paths + down_paths;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n,-1));
        if(m == 1 and n == 1) return 1;
        int ans = f(m, n,0, 0, dp);
        return dp[0][0];
    }
};
//optimal
//TC : O(n-1) or O(m-1) SC : O(1)
//no of right dirs = cols-1
//no of downward dirs = rows-1
//total no of directions = m+n-2
//if i am able to choose total right dirs or down dirs then i can get total no of paths(unique)
//(m+n-2)C(m-1) or (m+n-2)C(n-1) 
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m + n -2;
        int r = m - 1;
        long res = 1;
        for(int i = 1; i <= r; i++) {
            res = res*(N-r+i)/i;
        }
        return res;
    }
};