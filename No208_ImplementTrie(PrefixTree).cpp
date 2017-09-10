// 208. Implement Trie (Prefix Tree)

// Implement a trie with insert, search, and startsWith methods.

// Note:
// You may assume that all inputs are consist of lowercase letters a-z.
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

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int level;
        int len = word.size();
        int index;
        TrieNode *pCrawl = root;

        for(level=0; level < len; level++){
            index = word[level] - 'a';
            if(!pCrawl->children[index]){
                pCrawl->children[index] = new TrieNode();
            }
            pCrawl = pCrawl->children[index];
        }
        pCrawl->isLeaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int level;
        int len = word.size();
        int index;
        TrieNode *pCrawl = root;

        for(level=0; level < len; level++){
            index = word[level] - 'a';
            if(!pCrawl->children[index]){
                return false;
            }
            pCrawl = pCrawl->children[index];
        }

        // return (pCrawl!=nullptr && pCrawl->isLeaf);
        return (pCrawl->isLeaf);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int level;
        int len = prefix.size();
        int index;
        TrieNode *pCrawl = root;

        for(level=0; level < len; level++){
            index = prefix[level] - 'a';
            if(!pCrawl->children[index]){
                return false;
            }
            pCrawl = pCrawl->children[index];
        }
        return true;

    }
private:
    TrieNode *root;

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
