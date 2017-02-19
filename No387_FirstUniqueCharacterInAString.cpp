/*387. First Unique Character in a String
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.*/


// hashtable
/*class Solution {
public:
    int firstUniqChar(string s) {
        //only lowercase
        vector<int> hash(26, 0);
        for(int i=0; i<s.size(); i++){
        	hash[s[i]-'a']++;
        }
        for(int i=0; i<s.size(); i++){
        	if(hash[s[i]-'a']==1){
        		return i;
        	}
        }
        return -1;
    }
};*/

// improvement, no need twice loop s
// it is quicker than the above if the s is very long
class Solution{
public:
	int firstUniqChar(string s){
		//only lowercase
		//store index
		vector<pair<int,int> > hash(26, make_pair(0,INT_MAX));
		int index = s.size();
		for(int i=0; i<s.size(); i++){
			hash[s[i]-'a'].first++;
			hash[s[i]-'a'].second = i;
		}

		for(int i=0; i<hash.size(); i++){
			if(hash[i].first==1){
				index = min(index, hash[i].second);
			}
		}
		return index==s.size()? -1 : index;
	}
};