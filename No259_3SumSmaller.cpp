// 259. 3Sum Smaller

// Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

// For example, given nums = [-2, 0, 1, 3], and target = 2.

// Return 2. Because there are two triplets which sums are less than 2:

// [-2, 0, 1]
// [-2, 0, 3]
// Follow up:
// Could you solve it in O(n2) runtime?



class Solution {
public:
    // O(n^3) simple method
    int threeSumSmaller(vector<int>& nums, int target) {
        int res = 0;
        for(int i=0; i<nums.size()-2; i++){
            for(int j=i+1; j<nums.size()-1; j++){
                for(int k=j+1; k<nums.size(); k++){
                    if(nums[i]+nums[j]+nums[k] < target) res++;
                }
            }
        }

        return res;
    }
};



class Solution {
public:
    // O(n^2) method
    // Double pointers
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); // O(nlogn)
        int res = 0;
        for(int i=0; i+2 < nums.size(); i++){
            int left = i + 1;
            int right = nums.size()-1;

            while(left < right){
                if(nums[i] + nums[left] + nums[right] <target){
                    res += right - left; // no include the index of right, from left to right-1
                    left++;
                }
                else{ // value to big, try to shrink
                    right--;
                }
            }
        }

        return res;
    }
};

