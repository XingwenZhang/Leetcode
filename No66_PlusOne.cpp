// Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

// You may assume the integer do not contain any leading zero, except the number 0 itself.

// The digits are stored such that the most significant digit is at the head of the list.


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // Consider if the number is 9
        vector<int> res;
        int len = digits.size();
        // Initial carry to 1 , because it needs to plus one
        int carry = 1;
        int i = len-1;
        int temp = 0;
        while(i >= 0){
        	temp = digits[i] + carry;
        	// Update carry every loop
        	carry = temp / 10;
        	if(temp > 9){
        		temp = temp % 10;
        	}
        	i--;
        	res.push_back(temp);
        }
        if (carry != 0){
        	res.push_back(carry);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};