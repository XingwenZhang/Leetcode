// A message containing letters from A-Z is being encoded to numbers using the following mapping:

// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given an encoded message containing digits, determine the total number of ways to decode it.

// For example,
// Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

// The number of ways decoding "12" is 2.

// Solution 1: Recursion every two chars
class Solution {
public:
    int numDecodings(string s) {
    	if(s.empty()){
    		return 0;
    	}
    	int len = s.size();
    	int *dp = new int[len + 1];
    	dp[0] = 1;

    	// dp[i] means the first i chars solution
    	for(int i=1; i<=len; i++){
    		dp[i] = 0;
    	}

    	for(int i=1; i<=len; i++){
    		if(s[i-1] >= '1' && s[i-1] <= '9'){
    			dp[i] += dp[i-1];
    		}
    		if(i>=2 && s.substr(i-2,2).compare("10") >= 0 && s.substr(i-2,2).compare("26")<=0){
    			dp[i] += dp[i-2];
    		}
    	}
    	return dp[len];
    }
};