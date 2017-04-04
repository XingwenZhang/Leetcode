// Given a positive integer num, write a function which returns True if num is a perfect square else False.

// Note: Do not use any built-in library function such as sqrt.

// Example 1:

// Input: 16
// Returns: True
// Example 2:

// Input: 14
// Returns: False

class Solution {
public:
    bool isPerfectSquare(int num) {
    	if(num == 1){
    		return true;
    	}
        for(int i=1; i<=num/2; i++){
        	if(i * i == num){
        		return true;
        	}
        }
        return false;
    }
};