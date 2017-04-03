// The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

// Given two integers x and y, calculate the Hamming distance.

// Note:
// 0 ≤ x, y < 231.

// Example:

// Input: x = 1, y = 4

// Output: 2

// Explanation:
// 1   (0 0 0 1)
// 4   (0 1 0 0)
//        ↑   ↑

// The above arrows point to positions where the corresponding bits are different.


class Solution {
public:
	// This the most direct method, count the difference
    int hammingDistance(int x, int y) {
        int res = 0;
        while(x>0 && y>0){
        	if((x&1) != (y&1)){
        		res++;
        	}
        	x = x>>1;
        	y = y>>1;
        }
        while(x>0){
        	if(x&1){
        		res++;
        	}
        	x = x>>1;
        }
        while(y>0){
        	if(y&1){
        		res++;
        	}
        	y = y>>1;
        }
        return res;
    }
};


class Solution {
public:
	// xor count for the difference between two numbers
    int hammingDistance(int x, int y) {
    	int diff = x^y;
    	int res = 0;
    	while(diff != 0){
    		if(diff & 1){
    			res++;
    		}
    		diff = diff >> 1;
    	}
    	return res;
    }
};


class Solution {
public:
	// Third method, diff & diff - 1 convert the right most 1 to 0
    int hammingDistance(int x, int y) {
    	int diff = x^y;
    	int res = 0;
    	while(diff != 0){
    		res++;
    		diff = diff & (diff-1);
    	}
    	return res;
    }
};