// 209. Minimum Size Subarray Sum

// Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

// For example, given the array [2,3,1,2,4,3] and s = 7,
// the subarray [4,3] has the minimal length under the problem constraint.

// click to show more practice.

// More practice:
// If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).


class Solution {
public:
    // O(n) solution, sliding windows
    int minSubArrayLen(int s, vector<int>& nums) {
        int min_len = INT_MAX;
        int start = 0, end = 0;
        int sum = 0;
        while(end < nums.size()){
            while(sum < s && end < nums.size()){
                sum += nums[end];
                end++;
            }
            if(sum >= s){
                // Here cannot end >= start, because start will update in the future
                while(sum >= s && end > start){
                    sum -= nums[start];
                    start++;
                }
                // Update min_len in the if conditions
                min_len = min(min_len, end-start +1);
            }
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};
