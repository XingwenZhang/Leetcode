// 269. Alien Dictionary

// There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

// Example 1:
// Given the following words in dictionary,

// [
//   "wrt",
//   "wrf",
//   "er",
//   "ett",
//   "rftt"
// ]
// The correct order is: "wertf".

// Example 2:
// Given the following words in dictionary,

// [
//   "z",
//   "x"
// ]
// The correct order is: "zx".

// Example 3:
// Given the following words in dictionary,

// [
//   "z",
//   "x",
//   "z"
// ]
// The order is invalid, so return "".

// Note:
// You may assume all letters are in lowercase.
// You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
// If the order is invalid, return an empty string.
// There may be multiple valid order of letters, return any one of them is fine.


class Solution {
public:
    // directional graph, bfs, topological sort
    string alienOrder(vector<string>& words) {
        set<pair<char, char> > s; // store all sequence pair
        unordered_set<char> ch;
        vector<int> in(256, 0); // in-degree for all letters
        queue<char> q;
        string res = "";
        for(auto a : words) ch.insert(a.begin(), a.end()); // store all letters appear in the word list
        for(int i=0; i<words.size()-1; i++){
            int mn = min(words[i].size(), words[i+1].size());
            int j = 0;
            for(; j<mn; j++){
                if(words[i][j] != words[i+1][j]){
                    s.insert({words[i][j], words[i+1][j]}); // find pair and store
                    break;
                }
            }
            // if the prefix string doesn't appear before original string, then wrong
            if(j == mn && words[i].size() > words[i+1].size())
                return "";
        }

        for(auto item : s){
            in[item.second]++; // in-degree increses
        }

        for(auto item : ch){
            if(in[item] == 0){
                q.push(item);
                res += item;
            }
        }

        while(!q.empty()){
            char c = q.front(); q.pop();
            for(auto a : s){
                if(a.first == c){
                    --in[a.second];
                    if(in[a.second] == 0){
                        q.push(a.second);
                        res += a.second;
                    }
                }
            }
        }

        return res.size() == ch.size() ? res : "";
    }
};