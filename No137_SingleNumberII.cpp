// 137. Single Number II

// Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

// Note:
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?


class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	int count = 0;
    	int res = 0;
        for(int i=1; i<32; i++){
        	for(int j=0; j<nums.size(); j++){
        		if(((nums[j]<<i) & 0x80000000) == 0x80000000){
        			count += 1;
        		}

        	}
        	res = res | ((count%3) << (31-i));
        	count = 0;
        }
        // Judge the sign + or -
        for(int& k:nums){
        	if((k&0x80000000) == 0x80000000){
        		count += 1;
        	}
        }
        if (count % 3){
        	res |= 0x80000000;
        }

        return res;
    }

};