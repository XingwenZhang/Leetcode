// 179. Largest Number

// Given a list of non negative integers, arrange them such that they form the largest number.

// For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

// Note: The result may be very large, so you need to return a string instead of an integer.

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        struct{
            bool operator()(const int a, const int b){
                if(stol(to_string(a)+to_string(b)) > stol(to_string(b)+to_string(a))){
                    return true;
                }
                return false;
            }
        }mycomp;
        sort(nums.begin(), nums.end(), mycomp);
        string res;
        for(auto &item : nums){
            res += to_string(item);
        }
        res.erase(0, min(res.find_first_not_of('0'), res.size()-1));
        return res;
    }
};