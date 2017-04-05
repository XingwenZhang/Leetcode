// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

// For example,
// Given:
// s1 = "aabcc",
// s2 = "dbbca",

// When s3 = "aadbbcbcac", return true.
// When s3 = "aadbbbaccc", return false.


// class Solution {
// public:
// 	// Recursive method, compare each char
// 	// Time complexity T(n) = 2T(n-1)+c
// 	// so the time complexity is exponential
// 	// this solution will be TLE
//     bool isInterleave(string s1, string s2, string s3) {
//         if(s1.empty() && s2.empty() && s3.empty()){
//         	return true;
//         }
//         if(s3.empty()){
//         	return false;
//         }

//         return ((s1[0] == s3[0] && isInterleave(s1.substr(1, string::npos), s2, s3.substr(1, string::npos)))
//         	|| (s2[0] == s3[0] && isInterleave(s1, s2.substr(1, string::npos), s3.substr(1, string::npos))));
//     }
// };



class Solution {
public:
	// Dynamic Programming
	// s3's solution depends on s3[-2] and etc.
	// time complexity is MN, M is len of s1, N is len of s2
	// tabulation(bottom up)
    bool isInterleave(string s1, string s2, string s3) {
        int M = s1.size();
        int N = s2.size();
        if(s3.size() != M+N){
        	return false;
        }
        bool is_interleave[M+1][N+1];
        // Only initial 0 or 1, cannot initial other value
        memset(is_interleave, 0, sizeof(is_interleave)/sizeof(bool));

        for(int i=0; i<=M; i++){
        	for(int j=0; j<=N; j++){
        		// Initial the first value of position(0,0)
        		if(i==0 && j==0){
        			is_interleave[i][j] = true;
        		}
        		// If s1 is empty
        		else if(i==0 && s3[i+j-1] == s2[j-1]){
        			is_interleave[i][j] = is_interleave[i][j-1];
        		}
        		// If s2 is empty
        		else if(j==0 && s3[i+j-1] == s1[i-1]){
        			is_interleave[i][j] = is_interleave[i-1][j];
        		}
        		// If s3 matches with s1 but not s2
        		else if(s3[i+j-1] == s1[i-1] && s3[i+j-1] != s2[j-1]){
        			is_interleave[i][j] = is_interleave[i-1][j];
        		}
        		// If s3 mathces with s2 but not s1
        		else if(s3[i+j-1] == s2[j-1] && s3[i+j-1] != s1[i-1]){
        			is_interleave[i][j] = is_interleave[i][j-1];
        		}
        		// If s3 matches both with s1 and s2
        		else if(s3[i+j-1] == s1[i-1] && s3[i+j-1] == s2[j-1]){
        			is_interleave[i][j] = is_interleave[i-1][j] || is_interleave[i][j-1];
        		}
        	}
        }

        return is_interleave[M][N];
    }
};