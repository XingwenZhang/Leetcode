// 233. Number of Digit One

// Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

// For example:
// Given n = 13,
// Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.

class Solution {
public:
    int countDigitOne(int n) {

        if(n < 0) return 0;
        int q = n, x = 1, ans = 0;

        while(q > 0){
            int digit = q % 10; // get the last digit
            q /= 10; // reduce by 10
            ans += q * x; // base number of 1s

            if(digit == 1){
                ans += n % x + 1;
            }
            if(digit > 1){
                ans += x;
            }

            x *= 10;
        }


        return ans;
    }
};