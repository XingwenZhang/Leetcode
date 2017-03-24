// Implement int sqrt(int x).

// Compute and return the square root of x.


// Reference https://discuss.leetcode.com/topic/24532/3-4-short-lines-integer-newton-every-language
// Newton method
class Solution {
public:
    int mySqrt(int x) {
    	long r = x;
    	while (r*r > x)
        	r = (r + x/r) / 2;
    	return r;
    }
};