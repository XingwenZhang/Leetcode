// 243. Shortest Word Distance

// Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

// For example,
// Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

// Given word1 = “coding”, word2 = “practice”, return 3.
// Given word1 = "makes", word2 = "coding", return 1.

// Note:
// You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.


class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        vector<int> index1;
        vector<int> index2;
        for(int i=0; i<words.size(); i++){
            if(words[i] == word1){
                index1.push_back(i);
            }
            if(words[i] == word2){
                index2.push_back(i);
            }
        }

        int res = INT_MAX;
        for(int j=0; j<index1.size(); j++){
            for(int k=0; k<index2.size(); k++){
                res = min(res, abs(index1[j]-index2[k]));
            }
        }
        return res;
    }
};


class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int index_word1 = -1;
        int index_word2 = -1;
        int res = INT_MAX;

        for(int i=0; i<words.size(); i++){
            if(words[i] == word1){
                index_word1 = i;
                if(index_word2 != -1){
                    res = min(res, i - index_word2);
                }
            }

            if(words[i] == word2){
                index_word2 = i;
                if(index_word1 != -1){
                    res = min(res, i - index_word1);
                }
            }
        }

        return res;
    }
};