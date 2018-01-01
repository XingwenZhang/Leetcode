// 159. Longest Substring with At Most Two Distinct Characters

// Given a string, find the length of the longest substring T that contains at most 2 distinct characters.

// For example, Given s = “eceba”,

// T is "ece" which its length is 3.

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int res = 0, left = 0;

        unordered_map<char, int> hash_map;

        for(int i=0; i<s.size(); i++){
        	++hash_map[s[i]];

        	if(hash_map.size() > 2){
        		if(--hash_map[s[left]] == 0) hash_map.erase(s[left]);
        		left++;
        	}

        	res = max(res, i-left+1);
        }

        return res;
    }
};