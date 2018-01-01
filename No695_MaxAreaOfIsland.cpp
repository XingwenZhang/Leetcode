// 695. Max Area of Island

// Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

// Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

// Example 1:
// [[0,0,1,0,0,0,0,1,0,0,0,0,0],
//  [0,0,0,0,0,0,0,1,1,1,0,0,0],
//  [0,1,1,0,1,0,0,0,0,0,0,0,0],
//  [0,1,0,0,1,1,0,0,1,0,1,0,0],
//  [0,1,0,0,1,1,0,0,1,1,1,0,0],
//  [0,0,0,0,0,0,0,0,0,0,1,0,0],
//  [0,0,0,0,0,0,0,1,1,1,0,0,0],
//  [0,0,0,0,0,0,0,1,1,0,0,0,0]]
// Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
// Example 2:
// [[0,0,0,0,0,0,0,0]]
// Given the above grid, return 0.
// Note: The length of each dimension in the given grid does not exceed 50.

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = m == 0 ? 0 : grid[0].size();
        vector<vector<bool> > visited(m, vector<bool> (n, false));
        int res = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int tmp = 0;
                dfs(grid, visited, i, j, res, tmp);
            }
        }

        return res;

    }

    void dfs(vector<vector<int> >& grid, vector<vector<bool> >&visited, int i, int j, int& res, int& tmp){
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || grid[i][j] == 0){
            return;
        }

        visited[i][j] = true;

        res = max(res, ++tmp);

        for(int k=0; k<4; k++){
            dfs(grid, visited, i+x[k], j+y[k], res, tmp);
        }
    }
private:
    int x[4] = {0, 0, -1, 1};
    int y[4] = {1, -1, 0, 0};
};