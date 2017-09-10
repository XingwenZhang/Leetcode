
// 221. Maximal Square

// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

// For example, given the following matrix:

// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0
// Return 4.


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
		int m = matrix.size();
		if(m==0) return 0;
		int n = matrix[0].size();

		vector<vector<int> > dp(m, vector<int>(n,0));

		int max_edge = 0;

		for(int i=0; i<m; i++){
			dp[i][0] = matrix[i][0]-'0';
			max_edge = max(max_edge, dp[i][0]);
		}

		for(int j=0; j<n; j++){
			dp[0][j] = matrix[0][j]-'0'
;			max_edge = max(max_edge, dp[0][j]);
		}

		for(int i=1; i<m; i++){
			for(int j=1; j<n; j++){
				if(matrix[i][j] == '0'){
					dp[i][j] = 0;
				}
				else{
					dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
					max_edge = max(max_edge, dp[i][j]);
				}
				
			}
		}

		return max_edge*max_edge;
    }
};