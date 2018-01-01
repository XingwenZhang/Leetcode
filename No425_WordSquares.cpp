// 425. Word Squares

// Given a set of words (without duplicates), find all word squares you can build from them.

// A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).

// For example, the word sequence ["ball","area","lead","lady"] forms a word square because each word reads the same both horizontally and vertically.

// b a l l
// a r e a
// l e a d
// l a d y
// Note:
// There are at least 1 and at most 1000 words.
// All words will have the exact same length.
// Word length is at least 1 and at most 5.
// Each word contains only lowercase English alphabet a-z.
// Example 1:

// Input:
// ["area","lead","wall","lady","ball"]

// Output:
// [
//   [ "wall",
//     "area",
//     "lead",
//     "lady"
//   ],
//   [ "ball",
//     "area",
//     "lead",
//     "lady"
//   ]
// ]

// Explanation:
// The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
// Example 2:

// Input:
// ["abat","baba","atan","atal"]

// Output:
// [
//   [ "baba",
//     "abat",
//     "baba",
//     "atan"
//   ],
//   [ "baba",
//     "abat",
//     "baba",
//     "atal"
//   ]
// ]

// Explanation:
// The output consists of two word squares. The order of output does not matter (just the order of words in eac



class MyOwnTreeNode{
public:
    vector<MyOwnTreeNode*> children;
    vector<string> startsWith;
    MyOwnTreeNode(): children(26, nullptr){};
};

class Trie{
private:
    MyOwnTreeNode *root;
public:
    Trie(vector<string>& words){
        root = new MyOwnTreeNode();
        for(auto & word : words){
            MyOwnTreeNode *p = root;
            for(auto &ch : word){
                int idx = ch - 'a';
                if(!p->children[idx]) p->children[idx] = new MyOwnTreeNode();
                p = p->children[idx];
                p->startsWith.push_back(word);
            }
        }
    }
    vector<string> findByPrefix(string prefix){
        vector<string> res;
        MyOwnTreeNode *node = root;
        for(auto & ch : prefix){
            int idx = ch - 'a';
            if(!node->children[idx]) return res;
            node = node->children[idx];
        }
        for(auto & w : node->startsWith){
            res.push_back(w);
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        Trie trie(words);
        vector<vector<string> > res;
        if(words.empty() || words[0].empty()) return res;
        vector<string> temp;
        int len = words[0].size(); // All words have same length
        for(auto & word : words){
            temp.push_back(word);
            square_util(res, temp, len, trie);
            temp.pop_back();
        }
        return res;

    }
    void square_util(vector<vector<string> >& res, vector<string>& temp, int len, Trie & trie){
        if(temp.size() == len){
            res.push_back(temp);
            return;
        }
        int idx = temp.size();
        string prefix;
        for(auto word : temp){
            prefix.push_back(word[idx]);
        }
        vector<string> startsWith = trie.findByPrefix(prefix);
        for(auto word : startsWith){
            temp.push_back(word);
            square_util(res, temp, len, trie);
            temp.pop_back();
        }
    }
};