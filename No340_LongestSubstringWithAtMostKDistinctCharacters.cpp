// 340. Longest Substring with At Most K Distinct Characters

// Given a string, find the length of the longest substring T that contains at most k distinct characters.

// For example, Given s = “eceba” and k = 2,

// T is "ece" which its length is 3.

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(k <= 0){
            return 0;
        }
        unordered_map<char,int> diff_chars;
        int max_len = 0;
        int start = 0;
        for(int i=0; i<s.size(); i++){
            if(diff_chars.count(s[i])){ // already in
                diff_chars[s[i]] += 1;
            }
            else{
                if((int)diff_chars.size() < k){ // Here need to convert if k is negative
                    diff_chars[s[i]] = 1;
                }
                else{ // Cannot insert 
                    max_len = max(max_len, i-start);
                    while(diff_chars.size() >= k){ // need to pop up some char
                        if(diff_chars[s[start]] == 1){ // only one
                            diff_chars.erase(s[start]);
                            start++;
                        }
                        else{
                            diff_chars[s[start]]--;
                            start++;
                        }
                    }
                    diff_chars[s[i]] = 1;
                }
            }

        }
        return max_len = max(max_len, (int)s.size()-1-start);
    }
};

// There are some common in diff if conditions, so I can compress them
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(k <= 0){
            return 0;
        }
        unordered_map<char,int> diff_chars;
        int max_len = 0;
        int start = 0;
        for(int i=0; i<s.size(); i++){
            diff_chars[s[i]]++;
            while(diff_chars.size() > k){
                if(--diff_chars[s[start]] == 0){
                    diff_chars.erase(s[start]);
                }
                start++;
            }
            max_len = max(max_len, i-start+1);

        }
        return max_len;
    }
};