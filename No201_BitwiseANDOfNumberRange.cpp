// 201. Bitwise AND of Numbers Range

// Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

// For example, given the range [5, 7], you should return 4.


class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m==0){
            return 0;
        }

        int res = m;
        if(m != 2147483647){
            for(int i=m+1; i<n; i++){
            res &= i;
            if(res == 0){
                return 0;
            }
        }
        }
        else{
            return 2147483647;
        }
        
        res &= n;
        return res;
    }
};