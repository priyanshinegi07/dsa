
//TC : O(2*(n^m)) SC : O(1)
//we consider first row and col to mark the=m and extra col var to mark first col
//first we cange inner matrix then first row and then first col coz first row is dependent on first col
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int col0 = 1;//do not mark col 0
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                //if we encounter 0 then we will mak=rk the particular
                //row and col
                if(matrix[i][j] == 0) {
                    //marking row in first col
                    matrix[i][0] = 0;
                    //marking col in first row
                    if(j != 0)
                        matrix[0][j] = 0;
                    else 
                        col0 = 0;
                }
            }
        }
        for(int i = 0; i < cols; i++) {
            cout<<matrix[0][i]<<" ";
        }
        cout<<endl;
        //marked the inner matrix
        for(int i = 1; i < rows; i++) {
            for(int j = 1; j < cols; j++) {
                if(!matrix[i][0] or !matrix[0][j])
                    matrix[i][j] = 0;
            }
        }
        //mark the first row
        
        for(int i = 1; i < cols; i++) {
            if(!matrix[0][i] or !matrix[0][0])
                 matrix[0][i] = 0;
        }
        //mark the first col
       
        if(!col0)
            matrix[0][0] = 0;
        
        for(int i = 1; i < rows; i++) {
            if(!matrix[i][0] or !col0)
                 matrix[i][0] = 0;
        }


        return;
    }


//did myself
//TC : O(2*(n^m)) SC : O(n+m)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int>r;
        vector<int>c;
        for(int i = 0; i < rows;i++) {
            for(int j = 0; j < cols;j++) {
                if(matrix[i][j] == 0) {
                    r.push_back(i);
                    c.push_back(j);
                }
            }
        }
        cout<<c.size()<<" "<<r.size()<<endl;

        for(int row : r) {
            for(int i = 0; i < cols; i++) {
                matrix[row][i] = 0;
            }
            
        }
        for(int col : c) {
            cout<<"col "<<col<<" ";

            for(int i = 0; i < rows; i++) {
                matrix[i][col] = 0;
            }
            
        }
        return;
    }