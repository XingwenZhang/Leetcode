// Given an integer n, return the number of trailing zeroes in n!.

// Note: Your solution should be in logarithmic time complexity.


class Solution {
public:
	// The number of 0 is determined by the number of 5 and 2
	// and actually the number of 5 could decide the number of 0
	// because number of 5 is less than number of 2
	// and 25 could contains two 5 and so on
    int trailingZeroes(int n) {
        int res = 0;
        // avoid overflow
        for(long long int i=5; n/i>0; i*=5){
        	res += n/i;
        }
        return res;
    }
};