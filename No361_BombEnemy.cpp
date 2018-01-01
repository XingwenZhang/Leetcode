// 361. Bomb Enemy

// Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
// The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
// Note that you can only put the bomb at an empty cell.

// Example:
// For the given grid

// 0 E 0 0
// E 0 W E
// 0 E 0 0

// return 3. (Placing a bomb at (1,1) kills 3 enemies)

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = row == 0 ? 0 : grid[0].size();
        if(row == 0 || col == 0) return 0;
        
        vector<vector<int> > left2right(row, vector<int>(col, 0)), right2left = left2right, up2down = left2right,
        down2up = left2right;
        
        // left to right
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                int prev = (j==0 || grid[i][j] == 'W') ? 0 : left2right[i][j-1];
                left2right[i][j] = grid[i][j] == 'E' ? prev + 1 : prev;
            }
        }
        
        // right to left
        for(int i=row-1; i>=0; i--){
            for(int j=col-1; j>=0; j--){
                int prev = (j==col-1 || grid[i][j] == 'W') ? 0 : right2left[i][j+1];
                right2left[i][j] = grid[i][j] == 'E' ? prev+1 : prev;
            }
        }
        
        // up to down 
        for(int j=0; j<col; j++){
            for(int i=0; i<row; i++){
                int prev = (i==0 || grid[i][j] == 'W') ? 0 : up2down[i-1][j];
                up2down[i][j] = grid[i][j] == 'E' ? prev + 1 : prev;
            }
        }
        
        // down to up
        for(int j=col-1; j>=0; j--){
            for(int i=row-1; i>=0; i--){
                int prev = (i==row-1 || grid[i][j] == 'W') ? 0 : down2up[i+1][j];
                down2up[i][j] = grid[i][j] == 'E' ? prev + 1 : prev;
            }
        }
        int res = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == '0'){
                    res = max(res, left2right[i][j] + right2left[i][j] + up2down[i][j] + down2up[i][j]);
                }
            }
        }
        
        return res;
    }
};