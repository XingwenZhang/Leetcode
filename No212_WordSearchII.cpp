// 212. Word Search II

// Given a 2D board and a list of words from the dictionary, find all words in the board.

// Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

// For example,
// Given words = ["oath","pea","eat","rain"] and board =

// [
//   ['o','a','a','n'],
//   ['e','t','a','e'],
//   ['i','h','k','r'],
//   ['i','f','l','v']
// ]
// Return ["eat","oath"].
// Note:
// You may assume that all inputs are consist of lowercase letters a-z.

// hint:

// You would need to optimize your backtracking to pass the larger test. Could you stop backtracking earlier?

// If the current candidate does not exist in all words' prefix, you could stop backtracking immediately. What kind of data structure could answer such query efficiently? Does a hash table work? Why or why not? How about a Trie? If you would like to learn how to implement a basic trie, please work on this problem: Implement Trie (Prefix Tree) first.


class Solution {
public:
    class TrieNode{
    public:
        TrieNode* children[26];
        string str;
        TrieNode(){
            str = "";
            for(int i=0; i<26; i++){
                children[i] = nullptr;
            }
        }
    };

    class Trie{
    public:
        TrieNode* root;
        Trie(){
            root = new TrieNode();
        }
        void insert(string& s){
            TrieNode* p = root;
            for(auto& item : s){
                int index = item - 'a';
                if(!p->children[index]){
                    p->children[index] = new TrieNode();
                }
                p = p->children[index];
            }
            p->str = s;
        }

    };
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        vector<vector<bool> > visited(board.size(), vector<bool>(board[0].size(), false));

        // Build up trie tree with all words
        Trie trie;
        for(auto& item : words){
            trie.insert(item);
        }

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(trie.root->children[board[i][j]-'a']){ // Exist words start with this char, then dfs search the word on the board
                    dfs(board, visited, trie.root->children[board[i][j]-'a'], res, i, j);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char> >& board, vector<vector<bool> >& visited, TrieNode* p, vector<string>& res, int i, int j){
        if(!p->str.empty()){ // find a string
            res.push_back(p->str);
            // return;
            // Because want to find all words, so cannot stop even find one
            p->str.clear();
        }
        // Mark the cur board is visited
        visited[i][j] = true;
        for(int k=0; k<4; k++){
            int next_x = x[k] + i;
            int next_y = y[k] + j;

            if(next_x >= 0 && next_x < board.size() && next_y >= 0 && next_y < board[0].size() && p->children[board[next_x][next_y]-'a'] && !visited[next_x][next_y]){
                dfs(board, visited, p->children[board[next_x][next_y]-'a'], res, next_x, next_y);
            }
        }

        // Retrieve the state
        visited[i][j] = false;
    }
private:
    int x[4] = {0, 0, -1, 1};
    int y[4] = {1, -1, 0, 0};
};