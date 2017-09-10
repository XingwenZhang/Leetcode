
// 130. Surrounded Regions

// Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

// A region is captured by flipping all 'O's into 'X's in that surrounded region.

// For example,
// X X X X
// X O O X
// X X O X
// X O X X
// After running your function, the board should be:

// X X X X
// X X X X
// X X X X
// X O X X

// idea:
// check 4 borders and set all O and its neighbors to 1,
// then set all O to X,
// last set all 1 to O

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = 0;
        if(rows){
            cols = board[0].size();
        }
        if(!rows || !cols){
            return;
        }

        // Loop the 4 borders
        for(int i=0; i<rows; i++){
            bfs(board, i, 0);
            bfs(board, i, cols-1);
        }

        for(int j=0; j<cols; j++){
            bfs(board, 0, j);
            bfs(board, rows-1, j);
        }

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '1'){
                    board[i][j] = 'O';
                }
            }
        }

        
    }

    void bfs(vector<vector<char>>& board, int row, int col){
        int rows = board.size();
        int cols = board[0].size();

        queue<int> q;
        q.push(row*cols + col);

        while(!q.empty()){
            int index = q.front();
            q.pop();

            if(index < 0 || index >= rows * cols){
                continue;
            }

            int i = index / cols;
            int j = index % cols;

            if(board[i][j] == 'O'){
                board[i][j] = '1';
            }
            else{
                continue; // If its neighbor is not O, then stop
            }
            q.push(index - 1);
            q.push(index + 1);
            q.push(index + cols);
            q.push(index - cols);

        }
    }
};