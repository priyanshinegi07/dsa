#include<iostream>
using namespace std;
//brute go to every element and check
//TC : O(n*m) SC : O(1)

//optimal
//use bin search coz we have to search in sorted space
//IP_AS
//O(logm*n) coz this is the number of elements in visualized 1D arr
//if the indexing starts from 0 then the first element of next row will be a multiple of the number of colmns
//so if we divide mid by col no then we'll get the row no
//since first element is multiple of col number so if we take remainder by col then we can see ki first element se kitna aage h
class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col = matrix[0].size();
        int rows = matrix.size();
        int s = 0, e = rows * col - 1;
        while(s <= e) {
            int mid = s + (e - s) / 2;
            int i = mid / col;
            int j = mid % col;
            if(matrix[i][j] < target) {
                s = mid + 1;
            }
            else if(matrix[i][j] > target) {
                e = mid - 1;
            }
            else return true;
        }
        return false;
    }
};

//mysol
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int i = 0, j = col - 1;
        while(i < row and j >= 0) {
            if(matrix[i][j] == target) {
                return true;
            }
            if(matrix[i][j] > target) {
                //we go to prev col
                j--;
            }
            else {
                //we go to next row
                i++;
            }
        }
        return false;
    }
};