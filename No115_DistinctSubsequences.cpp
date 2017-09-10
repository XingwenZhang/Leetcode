// Given a string S and a string T, count the number of distinct subsequences of S which equals T.

// A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

// Here is an example:
// S = "rabbbit", T = "rabbit"

// Return 3.


// Solution 1: recursion, find the first char that s = t, then recursive the rest s and t
// class Solution {
// public:
//     int numDistinct(string s, string t) {
//         if(s.empty()){
//         	return t.size() == 0 ? 1 : 0;
//         }
//         if(t.empty()){
//         	return 1;
//         }
//         int res = 0;
//         for(int i=0; i<s.size(); i++){
//         	if(s[i] == t[0]){
//         		res += numDistinct(s.substr(i+1), t.substr(1));
//         	}
//         }
//         return res;
//     }
// };


// Solution 2: dp
class Solution{
public: 
	int numDistinct(string s, string t){
		if(s.empty()){
			return t.size() == 0 ? 1 : 0;
		}
		if(t.empty()){
			return 1;
		}
		vector<vector<int> > dp(s.size()+1, vector<int>(t.size()+1,0));

		for(int i=0; i<=s.size(); i++){
			dp[i][0]=1;
		}

		for(int i=1; i<=s.size(); i++){
			for(int j=1; j<=t.size(); j++){
				dp[i][j] = dp[i-1][j];
				if(s[i-1] == t[j-1]){
					dp[i][j] += dp[i-1][j-1];
				}
			}
		}

		return dp[s.size()][t.size()];
	}
};