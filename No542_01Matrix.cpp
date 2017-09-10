// 542. 01 Matrix

// Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

// The distance between two adjacent cells is 1.
// Example 1: 
// Input:

// 0 0 0
// 0 1 0
// 0 0 0
// Output:
// 0 0 0
// 0 1 0
// 0 0 0
// Example 2: 
// Input:

// 0 0 0
// 0 1 0
// 1 1 1
// Output:
// 0 0 0
// 0 1 0
// 1 2 1
// Note:
// The number of elements of the given matrix will not exceed 10,000.
// There are at least one 0 in the given matrix.
// The cells are adjacent in only four directions: up, down, left and right.

// 542. 01 Matrix

// Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

// The distance between two adjacent cells is 1.
// Example 1: 
// Input:

// 0 0 0
// 0 1 0
// 0 0 0
// Output:
// 0 0 0
// 0 1 0
// 0 0 0
// Example 2: 
// Input:

// 0 0 0
// 0 1 0
// 1 1 1
// Output:
// 0 0 0
// 0 1 0
// 1 2 1
// Note:
// The number of elements of the given matrix will not exceed 10,000.
// There are at least one 0 in the given matrix.
// The cells are adjacent in only four directions: up, down, left and right.

class Solution {
public:
    int rownum[4] = {-1, +1, 0, 0};
    int colnum[4] = {0, 0, -1, +1};
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        queue<pair<int,int>> q;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(matrix[i][j] == 0){
                    q.push(make_pair(i,j));
                }
                else{
                    matrix[i][j] = INT_MAX;
                }
            }
        }

        while(!q.empty()){
            pair<int,int> cur = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int r = cur.first + rownum[i];
                int c = cur.second + colnum[i];
                if(r<0 || c<0 || r>=rows || c>=cols || matrix[r][c] <= matrix[cur.first][cur.second]+1)
                    continue; // No need to update

                // Update 
                q.push(make_pair(r, c));
                matrix[r][c] = matrix[cur.first][cur.second] + 1;
            }
        }
        return matrix;

    }

};