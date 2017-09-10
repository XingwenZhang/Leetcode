
// 304. Range Sum Query 2D - Immutable

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
// sumRegion(1, 1, 2, 2) -> 11
// sumRegion(1, 2, 2, 4) -> 12
// Note:
// You may assume that the matrix does not change.
// There are many calls to sumRegion function.
// You may assume that row1 ≤ row2 and col1 ≤ col2.


// TLE
class NumMatrix {
public:
    vector<vector<int> > partial_sum;
    NumMatrix(vector<vector<int>> matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        partial_sum.assign(rows, vector<int>(cols, 0));
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                int sum = 0;
                for(int m=0; m<=i; m++){
                    for(int n=0; n<=j; n++){
                        sum += matrix[m][n];
                    }
                }
                partial_sum[i][j] = sum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 >= 1 && col1 >= 1)
            return partial_sum[row2][col2] - partial_sum[row1-1][col2] - partial_sum[row2][col1-1] + partial_sum[row1-1][col1-1];
        else if(row1 >= 1 && col1 < 1)
            return partial_sum[row2][col2] - partial_sum[row1-1][col2];
        else if(col1 >= 1 && row1 < 1)
            return partial_sum[row2][col2] - partial_sum[row2][col1-1];
        else 
            return partial_sum[row2][col2];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2)
 */





class NumMatrix {
public:
    vector<vector<int> > partial_sum;
    NumMatrix(vector<vector<int>> matrix) {
        if(matrix.empty() || matrix[0].empty())
            return;
        //partial_sum.resize(matrix.size(), vector<int>(matrix[0].size(), 0));
        int rows = matrix.size();
        int cols = matrix[0].size();
        partial_sum = vector<vector<int>>(rows+1, vector<int>(cols+1, 0));

        for(int i=1; i<=rows; i++){
            for(int j=1; j<=cols; j++){
                partial_sum[i][j] = partial_sum[i-1][j]+partial_sum[i][j-1] - partial_sum[i-1][j-1] + matrix[i-1][j-1];
            }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return partial_sum[row2+1][col2+1] - partial_sum[row1][col2+1] - partial_sum[row2+1][col1] + partial_sum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */