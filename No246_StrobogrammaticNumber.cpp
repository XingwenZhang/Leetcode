// 246. Strobogrammatic Number


// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

// Write a function to determine if a number is strobogrammatic. The number is represented as a string.

// For example, the numbers "69", "88", and "818" are all strobogrammatic.

class Solution {
public:
    bool isStrobogrammatic(string num) {
        if(num.empty()) return false;

        int len = num.size();

        // only 0, 1, 8, 6 and 9
        for(int i=0; i<=len/2; i++){
            if(num[i] != '0' && num[i] != '1' && num[i] != '8' && num[i] != '6' && num[i] != '9') return false;

            else if(num[i] == '6'){
                if(num[len-i-1] != '9') return false;
            }

            else if(num[i] == '9'){
                if(num[len-i-1] != '6') return false;
            }

            else{
                if(num[len-i-1] != num[i]) return false;
            }
        }

        return true;
    }
};