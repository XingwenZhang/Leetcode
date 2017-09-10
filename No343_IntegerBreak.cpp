// 343. Integer Break

// Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

// For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

// Note: You may assume that n is not less than 2 and not larger than 58.

// TLE
class Solution {
public:
    int integerBreak(int n) {
        return break_util(n, 0, 0, 0);
    }
    int break_util(int n, int k, int start, int end){
        if(end >= n && k>=1 ){
            return n-1-start+1;
        }
        if(end >= n && k<1){
            return 0;
        }
        return max(break_util(n, k+1, end+1, end+1) * (end-start+1),
            break_util(n, k, start, end+1));
    }
};

class Solution{
public:
    int integerBreak(int n){
        vector<vector<int> > cache(n, vector<int>(n, 0));
        return break_util2(n, 0, 0, cache);
    }
    int break_util2(int n, int start, int end, vector<vector<int> >& cache){
        if(end >= n && start != 0){
            return n-start;
        }
        if(end >= n && start == 0){
            return 0;
        }
        if(cache[start][end] != 0){
            return cache[start][end];
        }
        return cache[start][end] = max(break_util2(n, end+1, end+1, cache) * (end-start+1),
            break_util2(n, start, end+1, cache));
    }
};