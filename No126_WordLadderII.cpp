// 126. Word Ladder II

// Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

// Only one letter can be changed at a time
// Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
// For example,

// Given:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log","cog"]
// Return
//   [
//     ["hit","hot","dot","dog","cog"],
//     ["hit","hot","lot","log","cog"]
//   ]
// Note:
// Return an empty list if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.
// You may assume no duplicates in the word list.
// You may assume beginWord and endWord are non-empty and are not the same.
// UPDATE (2017/1/20):
// The wordList parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.

// TLE, 19/39 test cases
class Solution {
public:
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string> > vvs;
        vector<string> vs;
        int minlen = INT_MAX;
        vs.push_back(beginWord);
        ladder_util(vvs, vs, beginWord, endWord, wordList, beginWord,minlen);
        minlen = INT_MAX;
        for(auto v : vvs){
            if(v.size() < minlen){
                minlen = v.size();
            }
        }
        // Both two could pass the compilers.
        vvs.erase(remove_if(vvs.begin(), vvs.end(),[this](vector<string> v){return v.size()>minlen;}), vvs.end());
        //vvs.erase(remove_if(vvs.begin(), vvs.end(),[&](vector<string> v){return v.size()>minlen;}), vvs.end());

        return vvs;
    }

    void ladder_util(vector<vector<string> >& vvs, vector<string>& vs, string& bw, string& ew, vector<string>& wl, string& prev, int& minlen){
        if(prev == ew)
            if(vs.size() <= minlen){
                minlen = vs.size();
                vvs.emplace_back(vs);
            }

        for(auto s : wl){
            if(is_diff_one(prev, s) && find(vs.begin(), vs.end(), s) == vs.end()){
                vs.emplace_back(s);
                ladder_util(vvs, vs, bw, ew, wl, s,minlen);
                vs.pop_back();
            }
        }
    }
    bool is_diff_one(string& a, string& b){
        if(a.size() != b.size())
            return false;
        int cnt = 0;
        for(int i=0; i<a.size(); i++){
            if(a[i] != b[i])
                cnt++;
        }
        return cnt == 1 ? true : false;
    }
};


// a little improvment, no need to find minlen again, but in Lambda, minlen should be captured
// It is because [] expression is global scope, but minlen is local variable.
class Solution {
public:
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string> > vvs;
        vector<string> vs;
        int minlen = INT_MAX;
        vs.push_back(beginWord);
        ladder_util(vvs, vs, beginWord, endWord, wordList, beginWord,minlen);
        // minlen = INT_MAX;
        // for(auto v : vvs){
        //     if(v.size() < minlen){
        //         minlen = v.size();
        //     }
        // }
        // Both two could pass the compilers.
        vvs.erase(remove_if(vvs.begin(), vvs.end(),[this,minlen](vector<string> v){return v.size()>minlen;}), vvs.end());
        //vvs.erase(remove_if(vvs.begin(), vvs.end(),[&](vector<string> v){return v.size()>minlen;}), vvs.end());

        return vvs;
    }

    void ladder_util(vector<vector<string> >& vvs, vector<string>& vs, string& bw, string& ew, vector<string>& wl, string& prev, int& minlen){
        if(prev == ew)
            if(vs.size() <= minlen){
                minlen = vs.size();
                vvs.emplace_back(vs);
            }

        for(auto s : wl){
            if(is_diff_one(prev, s) && find(vs.begin(), vs.end(), s) == vs.end()){
                vs.emplace_back(s);
                ladder_util(vvs, vs, bw, ew, wl, s,minlen);
                vs.pop_back();
            }
        }
    }
    bool is_diff_one(string& a, string& b){
        if(a.size() != b.size())
            return false;
        int cnt = 0;
        for(int i=0; i<a.size(); i++){
            if(a[i] != b[i])
                cnt++;
        }
        return cnt == 1 ? true : false;
    }
};


// Still TLE, 19/39, a little improvment.
// So the key is the kernal algo
class Solution {
public:
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string> > vvs;
        vector<string> vs;
        int minlen = INT_MAX;
        vs.push_back(beginWord);
        ladder_util(vvs, vs, beginWord, endWord, wordList, beginWord,minlen);
        
        // Both two could pass the compilers.
        // vvs.erase(remove_if(vvs.begin(), vvs.end(),[this](vector<string> v){return v.size()>minlen;}), vvs.end());
        //vvs.erase(remove_if(vvs.begin(), vvs.end(),[&](vector<string> v){return v.size()>minlen;}), vvs.end());

        return vvs;
    }

    void ladder_util(vector<vector<string> >& vvs, vector<string>& vs, string& bw, string& ew, vector<string>& wl, string& prev, int& minlen){
        if(prev == ew){
            if(vs.size() < minlen){
                minlen = vs.size();
                vvs.clear();
                vvs.emplace_back(vs);
            }
            else if(vs.size() == minlen){
                vvs.emplace_back(vs);
            }
        }

        for(auto s : wl){
            if(is_diff_one(prev, s) && find(vs.begin(), vs.end(), s) == vs.end()){
                vs.emplace_back(s);
                ladder_util(vvs, vs, bw, ew, wl, s,minlen);
                vs.pop_back();
            }
        }
    }
    bool is_diff_one(string& a, string& b){
        if(a.size() != b.size())
            return false;
        int cnt = 0;
        for(int i=0; i<a.size(); i++){
            if(a[i] != b[i])
                cnt++;
        }
        return cnt == 1 ? true : false;
    }
};


// Try to add set<string> to reduce the find operation time complexity
class Solution {
public:
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string> > vvs;
        set<string> ss;
        vector<string> vs;
        int minlen = INT_MAX;
        vs.push_back(beginWord);
        ss.insert(beginWord);
        ladder_util(vvs, vs, ss, beginWord, endWord, wordList, beginWord,minlen);
        
        // Both two could pass the compilers.
        // vvs.erase(remove_if(vvs.begin(), vvs.end(),[this](vector<string> v){return v.size()>minlen;}), vvs.end());
        //vvs.erase(remove_if(vvs.begin(), vvs.end(),[&](vector<string> v){return v.size()>minlen;}), vvs.end());

        return vvs;
    }

    void ladder_util(vector<vector<string> >& vvs, vector<string>& vs, set<string>& ss, string& bw, string& ew, vector<string>& wl, string& prev, int& minlen){
        if(prev == ew){
            if(vs.size() < minlen){ //剪枝
                minlen = vs.size();
                vvs.clear();
                vvs.emplace_back(vs);
            }
            else if(vs.size() == minlen){
                vvs.emplace_back(vs);
            }
        }
            
        for(auto s : wl){
            if(is_diff_one(prev, s) && ss.insert(s).second){
                vs.emplace_back(s);
                // ss.insert(s);
                ladder_util(vvs, vs, ss, bw, ew, wl, s,minlen);
                vs.pop_back();
                ss.erase(s);
            }
        }
    }
    bool is_diff_one(string& a, string& b){
        if(a.size() != b.size())
            return false;
        int cnt = 0;
        for(int i=0; i<a.size(); i++){
            if(a[i] != b[i])
                cnt++;
        }
        return cnt == 1 ? true : false;
    }
};


// BFS and prune
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string> > res;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<string> p{beginWord}; // p is the temp path
        queue<vector<string> > paths; // all paths 
        paths.push(p);
        int level = 1, min_level = INT_MAX;
        unordered_set<string> words; // records the words already in the path

        while(!paths.empty()){
            auto t = paths.front();
            paths.pop();
            if(t.size() > level){
                for(auto w : words) dict.erase(w);
                words.clear();
                level = t.size();
                if(level > min_level) break;
            }

            string last = t.back(); // the previous word in path
            for(int i=0; i<last.size(); i++){
                string new_last = last;
                for(auto ch='a'; ch <='z'; ch++){
                    new_last[i] = ch;
                    if(!dict.count(new_last)) continue;
                    words.insert(new_last);
                    vector<string> next_path = t;
                    next_path.push_back(new_last);
                    if(new_last == endWord){
                        res.push_back(next_path);
                        min_level = level;
                    }
                    else{
                        paths.push(next_path);
                    }
                }
            }
        }
        return res;
    }
};
