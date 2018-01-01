// 289. Game of Life

// According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

// Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

// Any live cell with fewer than two live neighbors dies, as if caused by under-population.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by over-population..
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
// Write a function to compute the next state (after one update) of the board given its current state.

// Follow up: 
// Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
// In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?



// In place
// 4 states
// state 0 : dead to dead
// State 1 : live to live
// State 2 : live to dead
// State 3 : dead to live
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = m ? board[0].size() : 0;

        int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int cnt = 0;
                // iter all neighbors
                for(int k = 0; k<8; k++){
                    int x = i + dx[k], y = j + dy[k];
                    // state 1 and 2 mean the cell is live in this generation
                    if(x >= 0 && x < m && y >= 0 && y < n && (board[x][y] == 1 || board[x][y] == 2)){
                        cnt++;
                    }
                }

                if(board[i][j] && (cnt < 2 || cnt > 3)) board[i][j] = 2;
                else if(board[i][j] == 0 && cnt == 3) board[i][j] = 3;
            }
        }

        // Update all cells
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                board[i][j] %= 2;
            }
        }
    }
};