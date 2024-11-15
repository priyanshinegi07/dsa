class Solution {
public:
    bool is_valid(vector<vector<char>>&board, int row, int col, char ch) {
        for(int i = 0; i < 9; i++) {
            if(board[row][i] == ch) return false;
            if(board[i][col] == ch) return false;
            if(board[3 * (row/3) + i/3][3 * (col/3) + i%3] == ch) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>&board) {
    
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                //check if current pos is empty
                if(board[i][j] == '.') {
                    cout<<"hello"<<endl;
                    for(char c = '1'; c <= '9'; c++) {
                        if(is_valid(board, i, j, c)) {
                            //place the digit if it is a valid position
                            board[i][j] = c;
                            //return if we get a valid solution
                            if(solve(board)) {
                                return true;
                            }
                            else {
                                //backtrack 
                                board[i][j] = '.';
                            }
                        }
                    }
                    //if we have empty cell but we cannot fill it then we return false
                    return false;
                    
                }
            }
        }
        //if no empty cells then we return true
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};