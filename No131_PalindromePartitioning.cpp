// 131. Palindrome Partitioning

// Given a string s, partition s such that every substring of the partition is a palindrome.

// Return all possible palindrome partitioning of s.

// For example, given s = "aab",
// Return

// [
//   ["aa","b"],
//   ["a","a","b"]
// ]


class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> tmp;
        getPartitions(s,0,tmp,res);
        return res;
    }
private:
    void getPartitions(string& s, int idx, vector<string>& tmp,
        vector<vector<string>>& res){
        if(idx == s.size()){
            res.push_back(tmp);
            return;
        }
        for(int i=idx; i<s.size(); i++){
            int l = idx, r = i;
            while(l < r && s[l] == s[r]){
                l++;
                r--;
            }
            if(l >= r){
                tmp.push_back(s.substr(idx, i-idx+1));
                getPartitions(s, i+1, tmp, res);
                tmp.pop_back();
            }
        }
    }
};