// 211. Add and Search Word - Data structure design

// Design a data structure that supports the following two operations:

// void addWord(word)
// bool search(word)
// search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

// For example:

// addWord("bad")
// addWord("dad")
// addWord("mad")
// search("pad") -> false
// search("bad") -> true
// search(".ad") -> true
// search("b..") -> true
// Note:
// You may assume that all words are consist of lowercase letters a-z.

// click to show hint.

// You should be familiar with how a Trie works. If not, please work on this problem: Implement Trie (Prefix Tree) first.
const int SIZE = 26;

class TrieNode{
public:
    TrieNode *children[SIZE];
    bool isLeaf;
    TrieNode(){
        isLeaf = false;
        for(int i=0; i<SIZE; i++){
            children[i] = nullptr;
        }
    }
};


class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *pCrawl = root;
        int level = 0;
        int len = word.size();
        int index = 0;
        for(level=0; level<len; level++){
            index = word[level] - 'a';
            if(!pCrawl->children[index]){
                pCrawl->children[index] = new TrieNode();
            }
            pCrawl = pCrawl->children[index];
        }
        // Sign for ending
        pCrawl->isLeaf = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        TrieNode *pCrawl = root;
        //bool flag = true;
        bool find_flag = false;
        search_for_reg(pCrawl, find_flag, word, 0);
        if(find_flag){
            return true;
        }
        return false;
    }
private:
    TrieNode *root;
    void search_for_reg(TrieNode* node, bool &find_flag, string word, int level){
        if(!node || level > word.size() || find_flag){
            return;
        }
        if(level == word.size()){
            if(node->isLeaf)
                find_flag = true;
            return;
        }
        if(word[level]!='.'){
            int index = word[level] - 'a';
            if(!node->children[index]){
                //flag = false;
                return;
            }
            search_for_reg(node->children[index], find_flag, word, level+1);
        }
        else{
            for(int i=0; i<SIZE; i++){
                search_for_reg(node->children[i], find_flag, word, level+1);
            }
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */