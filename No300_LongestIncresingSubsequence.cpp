
// 300. Longest Increasing Subsequence

// Given an unsorted array of integers, find the length of longest increasing subsequence.

// For example,
// Given [10, 9, 2, 5, 3, 7, 101, 18],
// The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

// Your algorithm should run in O(n2) complexity.

// Follow up: Could you improve it to O(n log n) time complexity?


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        vector<int> LIS(nums.size(), 1);

        for(int i=1; i<LIS.size(); i++){
            for(int j=i-1; j>=0; j--){
                if(nums[i] > nums[j] && LIS[i] < LIS[j]+1){
                    LIS[i] = LIS[j] + 1;
                }
            }
        }
        int max_len = INT_MIN;
        for(int k=0; k<LIS.size(); k++){
            if(LIS[k] > max_len){
                max_len = LIS[k];
            }
        }
        return max_len;
    }
};