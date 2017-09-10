// 140. Word Break II

// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. You may assume the dictionary does not contain duplicate words.

// Return all such possible sentences.

// For example, given
// s = "catsanddog",
// dict = ["cat", "cats", "and", "sand", "dog"].

// A solution is ["cats and dog", "cat sand dog"].

// UPDATE (2017/1/4):
// The wordDict parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.


// TLE
// class Solution {
// public:
//     vector<string> wordBreak(string s, vector<string>& wordDict) {
//         vector<string> res;
//         string path;
//         int len = s.size();
//         word_break_util(res, path, s, wordDict, 0, len);
//         return res;
//     }

//     void word_break_util(vector<string>& res, string& path, string& s, vector<string>& wordDict, int start, int len){
//         if(start == len){
//             res.emplace_back(path.substr(0, path.size()-1));
//             return;
//         }
//         for(int i=start; i<len; i++){
//             string temp_s = s.substr(start, i-start+1);
//             if(find(wordDict.begin(), wordDict.end(), temp_s) != wordDict.end()){
//                 path += temp_s + ' ';
//                 word_break_util(res, path, s, wordDict, i+1, len);
//                 path.resize(path.size() - temp_s.size()-1); // substract the space
//             }
//         }
//     }
// };




class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        string path;
        int len = s.size();
        vector<bool> possible(len+1, true); // possible[i+1] true means s from i+1 to the end has solution
        word_break_util(res, path, s, wordDict, 0, len, possible);
        return res;
    }

    void word_break_util(vector<string>& res, string& path, string& s, vector<string>& wordDict, int start, int len, vector<bool>& possible){
        if(start == len){
            res.emplace_back(path.substr(0, path.size()-1));
            return;
        }
        for(int i=start; i<len; i++){
            string temp_s = s.substr(start, i-start+1);
            if(find(wordDict.begin(), wordDict.end(), temp_s) != wordDict.end()  && possible[i+1]){
                path += temp_s + ' ';
                int before = res.size();
                word_break_util(res, path, s, wordDict, i+1, len, possible);
                int after = res.size();
                if(after == before)
                    possible[i+1] = false;
                path.resize(path.size() - temp_s.size()-1); // substract the space
            }
        }
    }
};