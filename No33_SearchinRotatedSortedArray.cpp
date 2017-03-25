// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

// You are given a target value to search. If found in the array return its index, otherwise return -1.

// You may assume no duplicate exists in the array.


class Solution {
public:
    int search(vector<int>& nums, int target) {
        
    	int mid = 0;
    	int n = nums.size();
    	if(n==0){
    		return -1;
    	}
    	int low = 0, high  = n-1;

    	while(low < high){
    		mid = (low + high) / 2;
    		if(nums[mid] == target){
    			return mid;
    		}
    		// Find pivot
    		if(nums[mid] > nums[high]){
    			// Target is located between low and mid
    			if(nums[mid] > target && nums[low] <= target){
    				high = mid - 1;
    			}
    			// Target is located between mid and high
    			else{
    				low = mid + 1;
    			}
    		}
    		// Find pivot
    		else{
    			// Target is located between mid and high
    			if(nums[mid] < target && nums[high] >= target){
    				low = mid + 1;
    			}
    			// Target is located between low and mid
    			else{
    				high = mid - 1;
    			}
    		}


    	}
    	return nums[low] == target ? low : -1;
    }
};