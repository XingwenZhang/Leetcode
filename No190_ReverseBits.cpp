// Reverse bits of a given 32 bits unsigned integer.

// For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

// Follow up:
// If this function is called many times, how would you optimize it?

// Related problem: Reverse Integer


class Solution {
public:
	// Add one bits has two methods,
	// one is 0 | x
	// another one is 1 & x
    uint32_t reverseBits(uint32_t n) {
    	// res is a integer contains all 1s
        uint32_t res = 0;
        for(int i=0; i<32; i++){
        	res = res << 1;
        	res = res | (n&1);
        	n = n >> 1;
        }
        return res;
    }


};