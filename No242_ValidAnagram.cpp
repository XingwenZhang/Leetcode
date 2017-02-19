/*242. Valid Anagram

Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?*/

// sorting
/*class Solution {
public:
    bool isAnagram(string s, string t) {
    	if(s.size()!=t.size()){
    		return false;
    	}
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }
};
*/

//	hashtable
/*class Solution {
public:
    bool isAnagram(string s, string t) {
    	if(s.size() != t.size()){
    		return false;
    	}
        unordered_map<char,int> hashtable;
        for(int i=0; i<s.size(); i++){
        	hashtable[s[i]]++;
        	hashtable[t[i]]--;
        }
        unordered_map<char,int>::iterator it;
        for(it=hashtable.begin(); it!=hashtable.end(); it++){
        	if(it->second!=0){
        		return false;
        	}
        }
        return true;
    }
};*/

// hasttable improvement 
// use array to simulate the hashtable
class Solution {
public:
    bool isAnagram(string s, string t) {
    	if(s.size()!=t.size()){
    		return false;
    	}
        int character[26] = {0};
        for(int i = 0; i<s.size(); i++){
        	character[s[i]-'a']++;
        	character[t[i]-'a']--;
        }
        for(int j=0; j<26; j++){
        	if(character[j] != 0){
        		return false;
        	}
        }
        return true;
    }
};