// 491. Increasing Subsequences


// Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .

// Example:
// Input: [4, 6, 7, 7]
// Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
// Note:
// The length of the given array will not exceed 15.
// The range of integer in the given array is [-100,100].
// The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.


class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        set<vector<int>> res;
        vector<int> path;
        backtrack(res, path, nums, 0);
        vector<vector<int>> vec_res(res.begin(), res.end());
        return vec_res;


    }
    void backtrack(set<vector<int>>& res, vector<int>& path, vector<int>& nums, int pos){
        if(path.size() > 1){ // sequence length must be bigger than 2
            res.insert(path);
        }

        for(int i=pos; i<nums.size(); i++){
            if(!path.empty() && path.back() > nums[i]) continue;
            path.emplace_back(nums[i]);
            backtrack(res, path, nums, i+1);
            path.pop_back();
        }

    }
};