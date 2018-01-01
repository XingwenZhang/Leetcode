// 247. Strobogrammatic Number II

// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

// Find all strobogrammatic numbers that are of length = n.

// For example,
// Given n = 2, return ["11","69","88","96"].

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return findHelper(n, n);
    }

    vector<string> findHelper(int m, int n){
        if(m == 0) return {""};
        if(m == 1) return {"0", "1", "8"};

        vector<string> t = findHelper(m-2, n), res; // 2 ways fabonacci

        for(auto& item : t){
            if(m != n) res.push_back("0"+item + "0");
            res.push_back("1" + item + "1");
            res.push_back("8" + item + "8");
            res.push_back("6" + item + "9");
            res.push_back("9" + item + "6");
        }
        return res;

    }
};