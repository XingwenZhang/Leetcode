// 79. Word Search

// Given a 2D board and a word, find if the word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

// For example,
// Given board =

// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]
// word = "ABCCED", -> returns true,
// word = "SEE", -> returns true,
// word = "ABCB", -> returns false.

// DFS

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<int> x,y;
        vector<vector<bool> > visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == word[0]){
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }

        for(int k=0; k<x.size(); k++){
            if(dfs_util(x[k], y[k], 0, board, word, visited)){
                return true;
            }
        }
        return false;
    }
    bool dfs_util(int x, int y, int i, vector<vector<char> >& board, const string& word, vector<vector<bool> >& visited){
        if(is_valid(x,y,board.size(), board[0].size()) && !visited[x][y]){
            
            if(board[x][y] == word[i]){
                visited[x][y] = true;
                if(i == word.size() - 1)
                    return true;
                if( dfs_util(x+1, y, i+1, board, word, visited) || dfs_util(x-1, y, i+1, board, word, visited) 
                    || dfs_util(x, y+1, i+1, board, word, visited) || dfs_util(x, y-1, i+1, board, word, visited)){
                    return true;
                }
                
                visited[x][y] = false;
            }
            
        }
        return false;
    }
    bool is_valid(int x, int y, int rows, int cols){
        if(x>=0 && x<rows && y>=0 && y<cols)
            return true;
        return false;
    }
};




