// 220. Contains Duplicate III

// Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.


// TLE
// class Solution {
// public:
//     bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
//         list<int> sliding_window;
//         for(int i=0; i<nums.size(); i++){
//             if(i>k){
//                 sliding_window.pop_front();
//             }
//             for(auto item : sliding_window){
//                 if (abs(long(item)-nums[i]) <= t){
//                     return true;
//                 }
//             }
//             sliding_window.push_back(nums[i]);
//         }      
//         return false;
//     }
// };

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        // Using long because the test data has INT_MAX and INT_MIN
        set<long> sliding_window;
        for(int i=0; i<nums.size(); i++){
            if(i>k){
                sliding_window.erase(nums[i-k-1]);
            }
            auto pos = sliding_window.lower_bound(long(nums[i])-t);
            if(pos != sliding_window.end() && *pos-nums[i] <= t){
                return true;
            }
            sliding_window.insert(nums[i]);
        }
        return false;
    }
};