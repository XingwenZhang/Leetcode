// 248. Strobogrammatic Number III

// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

// Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.

// For example,
// Given low = "50", high = "100", return 3. Because 69, 88, and 96 are three strobogrammatic numbers.

// Note:
// Because the range might be a large number, the low and high numbers are represented as string.


class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int res = 0;

        findHelper(low, high, "", res);
        findHelper(low, high, "1", res);
        findHelper(low, high, "8", res);
        findHelper(low, high, "0", res);

        return res;
    }

    void findHelper(string low, string high, string path, int& res){
        if(path.size() >= low.size() && path.size() <= high.size()){
            if((path.size() == low.size() && path.compare(low) < 0) ||
                (path.size() == high.size() && path.compare(high) > 0)){
                return;
            }
            if(path[0] != '0' || path.size() <= 1) res++;
        }

        if(path.size() + 2 > high.size()) return;

        findHelper(low, high, "0" + path + "0", res);
        findHelper(low, high, "1" + path + "1", res);
        findHelper(low, high, "8" + path + "8", res);
        findHelper(low, high, "6" + path + "9", res);
        findHelper(low, high, "9" + path + "6", res);
    }
};