/*438. Find All Anagrams in a String
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".*/


// use isValidAnagram to help, but this is not so efficient
// time complexity O(slen*plen)
/*class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int len = s.size();
        int plen = p.size();
        vector<int> res;
        if(len == 0){
        	return res;
        }
        for(int i=0; i<len-plen+1; i++){
        	if(isValidAnagram(i, plen, s, p)){
        		res.push_back(i);
        	}
        }
        return res;
    }
private:
	bool isValidAnagram(int start, int len, string& s, string& p){
		int alpha[26] = {0};
		for(int i=0; i<len; i++){
			alpha[p[i]-'a']++;
			alpha[s[start+i]-'a']--;
		}
		for(int i=0; i<26; i++){
			if(alpha[i]!=0){
				return false;
			}
		}
		return true;
	}
};*/

// sliding window
// much more quicker than before
// time complexity is O(n)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.size()==0){
        	return res;
        }

        vector<int> hash(256,0);
        // if use int *hash = new int[256]; error, because the default value
        for(auto i:p){
        	hash[i]++;
        }

        int left = 0, right = 0, count = p.size();

        while(right < s.size()){
        	if(hash[s[right]] >= 1){
        		count--;
        	}
        	hash[s[right]]--;
        	right++;

        	if(count == 0){
        		res.push_back(left);
        	}

        	if(right - left == p.size()){
        		if(hash[s[left]] >= 0){
        			count++;
        		}

        		hash[s[left]]++;
        		left++;
        	}

        }
       
        return res;
    }
};