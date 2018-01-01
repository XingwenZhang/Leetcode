// 254. Factor Combinations

// Numbers can be regarded as product of its factors. For example,

// 8 = 2 x 2 x 2;
//   = 2 x 4.
// Write a function that takes an integer n and return all possible combinations of its factors.

// Note: 
// You may assume that n is always positive.
// Factors should be greater than 1 and less than n.
// Examples: 
// input: 1
// output: 
// []
// input: 37
// output: 
// []
// input: 12
// output:
// [
//   [2, 6],
//   [2, 2, 3],
//   [3, 4]
// ]
// input: 32
// output:
// [
//   [2, 16],
//   [2, 2, 8],
//   [2, 2, 2, 4],
//   [2, 2, 2, 2, 2],
//   [2, 4, 4],
//   [4, 8]
// ]


class Solution {
public:
    vector<vector<int>> getFactors(int n) {

        vector<vector<int> > res;
        if(n <= 2) return res;

        vector<int> path;
        int start = 2;
        int remain = n;

        getFactorsHelper(res, path, start, remain);
        return res;

    }
private:
    void getFactorsHelper(vector<vector<int> >& res, vector<int>& path, int start, int remain){
        if(remain == 1){
            if(path.size() > 1){
                res.push_back(path);
            }
            return;
        }

        for(int i=start, i <= remain; i++){
            if(remain % i == 0){
                path.push_back(i);
                getFactorsHelper(res, path, i, remain/i);
                path.pop_back();
            }
        }

    }
};