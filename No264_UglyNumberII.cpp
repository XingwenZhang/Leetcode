// Write a program to find the n-th ugly number.

// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

// Note that 1 is typically treated as an ugly number, and n does not exceed 1690.

// Credits:
// Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.


class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly_num;
        ugly_num.emplace_back(1);
        int i2=0,i3=0,i5=0;

        while(ugly_num.size() != n){
            int next_ugly_num = min(min(ugly_num[i2]*2,ugly_num[i3]*3),ugly_num[i5]*5);
            ugly_num.emplace_back(next_ugly_num);
            if(next_ugly_num == ugly_num[i2]*2){
                i2++;
            }
            // Cannot else if, for example 6 is equal to 2*3, if use "else if", 6 will count twice
            if(next_ugly_num == ugly_num[i3]*3){
                i3++;
            }
            if(next_ugly_num == ugly_num[i5]*5){
                i5++;
            }
        }
        return ugly_num.back();
    }
};