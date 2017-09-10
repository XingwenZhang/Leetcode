// Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

// For example:

// Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

// Note:
// The order of the result is not important. So in the above example, [5, 3] is also correct.
// Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
// Credits:
// Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_val = 0, first = 0, second = 0;

        for(auto& i:nums){
            xor_val ^= i;
        }
        int bit_rightmost = xor_val & (~(xor_val-1));

        for(auto& i : nums){
            if(i&bit_rightmost){
                first ^= i;
            }
            else
                second ^= i;
        }
        vector<int> res;
        res.push_back(first);
        res.push_back(second);
        return res;
    }
};