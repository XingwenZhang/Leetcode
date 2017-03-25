// Given a collection of integers that might contain duplicates, nums, return all possible subsets.

// Note: The solution set must not contain duplicate subsets.

// For example,
// If nums = [1,2,2], a solution is:

// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> path;
        if(n == 0){
        	return res;
        }
        
        sort(nums.begin(), nums.end());
        backtrack(res, path, nums, 0);
        return res;
    }
private:
	void  backtrack(vector<vector<int>> &res, vector<int> &path, vector<int> &nums, int pos){
		res.push_back(path);
		for(int i=pos; i<nums.size(); i++){
			// Handle for duplicates
			// Only take the first one into consideration
			if(i!=pos && nums[i]==nums[i-1]){
				continue;
			}
			path.push_back(nums[i]);
			backtrack(res, path, nums, i+1);
			path.pop_back();
		}
	}
};