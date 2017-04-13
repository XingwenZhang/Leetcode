// Implement wildcard pattern matching with support for '?' and '*'.

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).

// The matching should cover the entire input string (not partial).

// The function prototype should be:
// bool isMatch(const char *s, const char *p)

// Some examples:
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "*") → true
// isMatch("aa", "a*") → true
// isMatch("ab", "?*") → true
// isMatch("aab", "c*a*b") → false


class Solution {
public:
    bool isMatch(string s, string p) {
        
    	int len_s = s.size();
    	int len_p = p.size();

    	if(len_p == 0){
    		return len_s == 0;
    	}

    	bool lookup[len_s+1][len_p+1];
    	memset(lookup, false, sizeof(lookup)/sizeof(bool));

    	// Initialization 
    	lookup[0][0] = true;

    	for(int j=1; j<=len_p; j++){
    		if(p[j-1] == '*'){
    			lookup[0][j] = lookup[0][j-1];
    		}
    	}

    	// DP
    	for(int i=1; i<=len_s; i++){
    		for(int j=1; j<=len_p; j++){
    			if(p[j-1] == '*'){
    				lookup[i][j] = lookup[i][j-1] || lookup[i-1][j];
    			}

    			if(p[j-1] == '?'){
    				lookup[i][j] = lookup[i-1][j-1];
    			}

    			if(p[j-1] == s[i-1]){
    				lookup[i][j] = lookup[i-1][j-1];
    			}
    			else{
    				lookup[i][j] = false;
    			}
    		}
    	}


    	return lookup[len_s][len_p];


    }
};