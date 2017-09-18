// 416. Partition Equal Subset Sum

// Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

// Note:
// Each of the array element will not exceed 100.
// The array size will not exceed 200.
// Example 1:

// Input: [1, 5, 11, 5]

// Output: true

// Explanation: The array can be partitioned as [1, 5, 5] and [11].
// Example 2:

// Input: [1, 2, 3, 5]

// Output: false

// Explanation: The array cannot be partitioned into equal sum subsets.

// TLE 理所当然TLE，哈哈
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = accumulate(nums.begin(), nums.end(), 0);
        if(target % 2 != 0){
            return false;
        }
        target = target / 2;
        return part_util(nums, target, 0, 0);
    }

    bool part_util(vector<int>& nums, int target, int sum, int index){
        if(sum == target){
            return true;
        }

        if(index >= nums.size()){
            return false;
        }

        return part_util(nums, target, sum+nums[index], index+1) || part_util(nums, target, sum, index+1);

    }
};


class Solution{
public:
    bool canPartition(vector<int>& nums){
        int target = accumulate(nums.begin(), nums.end(), 0);
        if(target % 2 != 0){
            return false;
        }
        target = target / 2;
        vector<vector<int> > cache(target+1, vector<int>(nums.size()+1, -1));
        return part_util2(nums, target, 0, cache);
    }
    bool part_util2(vector<int>& nums, int target, int index, vector<vector<int> >& cache){
        if(target == 0){
            return true;
        }
        if(index >= nums.size() || target < 0){
            return false;
        }
        if(cache[target][index] != -1){
            return cache[target][index] == 0 ? false : true;
        }

        if(part_util2(nums, target, index+1, cache) || part_util2(nums, target-nums[index], index+1, cache)){
            cache[target][index] = 1;
            return true;
        }
        else{
            cache[target][index] = 0;
            return false;
        }
    }
};