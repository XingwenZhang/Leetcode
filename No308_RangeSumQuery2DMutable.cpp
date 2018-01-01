// 308. Range Sum Query 2D - Mutable

// Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

// Range Sum Query 2D
// The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

// Example:
// Given matrix = [
//   [3, 0, 1, 4, 2],
//   [5, 6, 3, 2, 1],
//   [1, 2, 0, 1, 5],
//   [4, 1, 0, 1, 7],
//   [1, 0, 3, 0, 5]
// ]

// sumRegion(2, 1, 4, 3) -> 8
// update(3, 2, 2)
// sumRegion(2, 1, 4, 3) -> 10
// Note:
// The matrix is only modifiable by the update function.
// You may assume the number of calls to update and sumRegion function is distributed evenly.
// You may assume that row1 ≤ row2 and col1 ≤ col2.


// Each row is binary indexed tree
class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        this->rows = matrix.size();
        this->cols = this->rows == 0 ? 0 : matrix[0].size();
        if (this->rows == 0 || this->cols == 0 ) return;
        this->matrix = vector<vector<int> >(rows + 1, vector<int>(cols+1, 0));
        this->sum = vector<vector<int> >(rows + 1, vector<int> (cols + 1, 0));
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                update(i, j, matrix[i][j]);
            }
        }
    }
    
    void update(int row, int col, int val) { // Update one number will influence one row
        int diff = val - this->matrix[row+1][col+1]; // Here should add one
        // for(int i=row+1; i<= this->rows; i++){

            for(int j=col+1; j<= this->cols; j+=(j&-j)){
                sum[row+1][j] += diff;
            }
        // }
        this->matrix[row+1][col+1] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) { // Here the index is from origin matrix
        // int top_left_row = row1;
        // int top_left_col = col1;
        // int top_right_row = row1;
        // int top_right_col = col2;
        // int bot_left_row = row2;
        // int bot_left_col = col1;
        // int bot_right_row = row2;
        // int bot_right_col = col2;
        int res = 0;
        for(int i=row1+1; i<=row2+1; i++){ // Transfer index to binary indexed tree
            res += getSum(i, col2+1) - getSum(i, col1);
        }
        return res;
    }

    int getSum(int row1, int col1){
        int res = 0;
        for(int j=col1; j>0; j-=(j&-j)){
            res += sum[row1][j];
        }
        return res;
    }
private:
    int rows;
    int cols;
    vector<vector<int> > matrix;
    vector<vector<int> > sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */