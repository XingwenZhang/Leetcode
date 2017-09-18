// 377. Combination Sum IV

// Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

// Example:

// nums = [1, 2, 3]
// target = 4

// The possible combination ways are:
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)

// Note that different sequences are counted as different combinations.

// Therefore the output is 7.
// Follow up:
// What if negative numbers are allowed in the given array?
// How does it change the problem?
// What limitation we need to add to the question to allow negative numbers?

// TLE， 妥妥TLE了，这个子集太大了~~~，照着DP的思路去想想
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int times = 0;
        vector<int> v;
        combination_util(nums, v, 0, target, times);
        return times;
    }
    void combination_util(vector<int>& nums, vector<int>& v, int index, int target, int& times){
        if(index >= nums.size()){
            return;
        }
        if(accumulate(v.begin(), v.end(), 0) == target){
            times++;
            return;
        }
        for(int i=index; i<nums.size(); i++){
            v.push_back(nums[i]);
            combination_util(nums, v, index+1, target);
            v.pop_back();
        }
    }
};



class Solution{
public:
    int combinationSum4(vector<int>& nums, int target){
        vector<int> dp(target+1, 0); // dp[i] if target is i, the number of combinations
        dp[0] = 1;
        for(int i=1; i<=target; i++){
            for(auto& m : nums){
                if(i >= m) dp[i] += dp[i-a];
            }
        }
        return dp.back();
    }
};


// 与第一个方法类似，因为我们这道题不需要具体的组成，只是组成的数目，因此在递归上可以有所简化
// 这个肯定会TLE，所以需要一定优化
class Solution{
public:
    int combinationSum4(vector<int>& nums, int target){
        if(target == 0)
            return 1; // target == 0 -> last layer: target == nums[i], so target only have 1 combination
        int res = 0;
        for(int i=0; i<nums.size(); i++){
            if(target >= nums[i]){
                res += combinationSum4(nums, target-nums[i]);
            }
        }
        return res;
    }
};

// AC top-down
class Solution{
public:
    int combinationSum4(vector<int>& nums, int target){
        vector<int> cache(target+1, -1);
        return combination_util2(nums, target, cache);
    }
    int combination_util2(vector<int>& nums, int target, vector<int>& cache){
        if(target == 0){
            return 1;
        }
        if(cache[target] != -1){
            return cache[target];
        }
        int res = 0;
        for(int i=0; i<nums.size(); i++){
            if(target >= nums[i]){
                res += combination_util2(nums, target-nums[i], cache);
            }
        }
        return cache[target] = res;
    }
};
