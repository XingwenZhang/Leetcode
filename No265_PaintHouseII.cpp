// 265. Paint House II

// There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

// The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

// Note:
// All costs are positive integers.

// Follow up:
// Could you solve it in O(nk) runtime?

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if(costs.empty() || costs[0].empty()) return 0;
        vector<vector<int> > dp = costs;

        int cnt = costs[0].size(); // number of diff color

        for(int i=1; i<dp.size(); i++){
            for(int j=0; j<dp[0].size(); j++){
                int prev_min = INT_MAX;
                for(int k=1; k<cnt; k++){
                    prev_min = min(prev_min, dp[i-1][(j+k)%cnt]);
                }
                dp[i][j] += prev_min;
            }
        }


        int res = INT_MAX;
        for(int i=0; i<cnt; i++){
            res = min(res, dp.back()[i]);
        }

        return res;
    }
};

// follow up: time complexity O(nk)
class Solution {
public:
    // store two vars, one min, one second to min
    // If next layer is with the same color with min
    // Use second to min to update
    int minCostII(vector<vector<int>>& costs) {
        if(costs.empty() || costs[0].empty()) return 0;
        vector<vector<int> > dp = costs;
        int min1 = -1, min2 = -1;
        for(int i=0; i<dp.size(); i++){
            int last1 = min1, last2 = min2;
            min1 = -1; min2 = -1;

            for(int j=0; j<dp[0].size(); j++){
                if(j != last1){
                    dp[i][j] += last1 < 0 ? 0 : dp[i-1][last1];
                }
                else{
                    dp[i][j] += last2 < 0 ? 0 : dp[i-1][last2];
                }

                if(min1 < 0 || dp[i][j] < dp[i][min1]){
                    min2 = min1;
                    min1 = j;
                }
                else if(min2 < 0 || dp[i][j] < dp[i][min2]){
                    min2 = j;
                }
            }
        } 
        return dp.back()[min1]; 
    }
};