// 228. Summary Ranges

// Given a sorted integer array without duplicates, return the summary of its ranges.

// For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

// Credits:
// Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int lower=0, upper=0;
        vector<string> res;
        int len = nums.size();
        if(len == 0){
            return res;
        }
        if(len == 1){
            res.push_back(to_string(nums[0]));
            return res;
        }

        while(upper < len-1){
            upper++;
            if(nums[upper] - 1 != nums[upper-1]){
                string temp;
                temp += to_string(nums[lower]);
                if(lower != upper-1){
                    temp += "->";
                    temp += to_string(nums[upper-1]);
                }
                res.push_back(temp);
                lower = upper;
            }
        }
        string temp;
        temp += to_string(nums[lower]);
        if(lower != upper){
            temp += "->";
            temp += to_string(nums[upper]);
        }
        res.push_back(temp);

        return res;

    }
};