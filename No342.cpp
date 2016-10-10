class Solution {
public:
    bool isPowerOfFour(int num) {
        return ((log(num)/log(4))==1);
    }
};