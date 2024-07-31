#include<iostream>
using namespace std;

//push 0th and 1st row
//on the basis of this generate elements of below row
//TC : O(n^2) SC : O(n^2)
class Solution {
public:
    void generate_row(int row_size, vector<vector<int>>&ans) {
        vector<int>temp(row_size+1);
        temp[0] = 1;
        temp[row_size] = 1;
        int n = ans[ans.size() - 1].size();
        for(int index = 1; index < row_size; index++) {
            temp[index] = ans[n  - 1][index - 1] + ans[n - 1][index];
        }
        ans.push_back(temp);
        return;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back({1});
        if(numRows == 1) return ans;
        ans.push_back({1, 1});
        if(numRows == 2) return ans;

        for(int i = 2; i < numRows; i++) {
            generate_row(i, ans);
        }
        return ans;
    }
};
//TC : O(n^2) SC : O(1)
// Time Complexity: O(n2), where n = number of rows(given).
// Reason: We are generating a row for each single row. The number of rows is n. And generating an entire row takes O(n) time complexity.
class Solution {
public: void generate_row(int i, vector<vector<int>>&result) {
    vector<int>temp;
    temp.push_back(1);
    long long ans = 1;
    for(int col = 1; col < i; col++) {
        ans = ans * (i - col);
        ans /= col;
        temp.push_back(ans);
    }
    result.push_back(temp);
    // return result;
}

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back({1});
        for(int i = 2; i <= numRows; i++) {
            generate_row(i, ans);

        }
        return ans;
    }
};