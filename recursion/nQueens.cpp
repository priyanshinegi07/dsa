class Solution {
public:
    bool can_place(vector<string>board, int row, int col, int n) {
        int temp_row = row, temp_col = col;
        //check whether there is attack from top left diagonal
        while(row >= 0 and col >= 0) {
            if(board[row][col] == 'Q') return false;
            row--, col--;
        }
        row = temp_row; col = temp_col;
        //check whether there is attack from current col towards left
        while(col >= 0) {
            if(board[row][col] == 'Q') return false;
            col--;
        }

        row = temp_row; col = temp_col;
        //check whether there is attack from bottom left diagonal
        while(col >= 0 and row < n) {
            if(board[row][col] == 'Q') return false;
            col--;
            row++;
        }
        return true;
    }
    void solve(int col, int n, vector<vector<string>>&ans, vector<string>board) {
        //base case
        if(col == n) {
            ans.push_back(board);
            return;
        }
        //recursive case
        for(int row = 0; row < n; row++) {
            if(can_place(board, row, col, n)) {
                board[row][col] = 'Q';
                solve(col + 1 , n, ans, board);
                board[row][col] = '.';
            }
        }
    }
    void solve2(int col, int n, vector<vector<string>>&ans, vector<string>board, vector<int>&upper_diagonal, vector<int>&lower_diagonal, vector<int>&left_row) {
        //base case
        if(col == n) {
            ans.push_back(board);
            return;
        }
        //recursive case
        for(int row = 0; row < n; row++) {
            if(left_row[row] == 0 and upper_diagonal[n - 1 + col - row] == 0 and lower_diagonal[row + col] == 0) {
                board[row][col] = 'Q';
                left_row[row] = 1;
                upper_diagonal[n - 1 + col - row] = 1;
                lower_diagonal[row + col] = 1;
                solve2(col + 1 , n, ans, board, upper_diagonal, lower_diagonal, left_row);
                board[row][col] = '.';
                left_row[row] = 0;
                upper_diagonal[n - 1 + col - row] = 0;
                lower_diagonal[row + col] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string s(n, '.');
        vector<string>board(n, s);
        vector<int> upper_diagonal(2*n - 1, 0), lower_diagonal(2*n - 1, 0), left_row(n, 0);
        solve2(0, n, ans, board, upper_diagonal, lower_diagonal, left_row);
        return ans;
    }
};