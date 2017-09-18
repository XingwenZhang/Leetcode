// 467. Unique Substrings in Wraparound String

// Consider the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so s will look like this: "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".

// Now we have another string p. Your job is to find out how many unique non-empty substrings of p are present in s. In particular, your input is the string p and you need to output the number of different non-empty substrings of p in the string s.

// Note: p consists of only lowercase English letters and the size of p might be over 10000.

// Example 1:
// Input: "a"
// Output: 1

// Explanation: Only the substring "a" of string "a" is in the string s.
// Example 2:
// Input: "cac"
// Output: 2
// Explanation: There are two substrings "a", "c" of string "cac" in the string s.
// Example 3:
// Input: "zab"
// Output: 6
// Explanation: There are six substrings "z", "a", "b", "za", "ab", "zab" of string "zab" in the string s.


// TLE 最后一个非常大的string
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        string wrap = "abcdefghijklmnopqrstuvwxyz";
        set<string> v;
        substrings_util2(v, p);
        int res = 0;
        for(auto i : v){ // set的时候这里不能使用&引用，因为set中的string是const 
            if(contain_util(i, wrap)){
                res++;
            }
        }
        return res;
    }
    // void substrings_util(vector<string>& v, string& s, string& p, int index, int n){
    //     if(n <= 0){
    //         v.push_back(s);
    //         return;
    //     }
    //     for(int i=index; i<p.size(); i++){
    //         s.push_back(p[i]);
    //         substrings_util(v, s, p, i+1, n-1);
    //         s.pop_back();
    //     }
    // }
    bool contain_util(string& sub, string& wrap){
        int start = wrap.find(sub[0]);
        for(int i=1; i<sub.size(); i++){
            if(wrap[(start+i)%26] != sub[i] ){
                return false;
            }
        }
        return true;
    }
    void substrings_util2(set<string>& v, string& s){
        int sz = s.size();
        for(int len = 1; len <= sz; len++){
            for(int i=0; i<=sz-len; i++){
                v.insert(s.substr(i, len));
            }
        }
    }
};

// 求出以每个字母结束的最长子串长度，然后求和即可。
// 例如abcd 包括了abcd, bcd, cd, d四个子串，恰好是最长子串的长度
class Solution{
public:
    int findSubstringInWraproundString(string p){
        vector<int> v(26, 0);
        int len = 0;
        for(int i=0; i<p.size(); i++){
            if(i>0 && (p[i]-p[i-1] == 1 || p[i-1]-p[i] == 25)){ // 25 means za
                len++;
            }
            else{
                len=1;
            }
            v[p[i]-'a'] = max(v[p[i]-'a'], len);
        }
        return accumulate(v.begin(), v.end(), 0);
    }
};