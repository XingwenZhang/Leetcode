// 162. Find Peak Element

// A peak element is an element that is greater than its neighbors.

// Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

// The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

// You may imagine that num[-1] = num[n] = -∞.

// For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

// click to show spoilers.

// Note:
// Your solution should be in logarithmic complexity.

class Solution {
public:
    // log(n) means binary search
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1){
            return 0;
        }
        int l = 0;
        int r = nums.size()-1;
        int mid = -1;
        while(l+1 < r){
            mid = (l+r) / 2;

            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                return mid;
            }

            else if(nums[mid] > nums[mid-1] && nums[mid] < nums[mid+1]){
                l = mid;
            }
            else if(nums[mid] < nums[mid-1] && nums[mid] > nums[mid+1]){
                r = mid;
            }
            else{
                // random choose 
                l = mid;
            }
        }
        if(nums[l] > nums[r]){
            return l;
        }
        if(nums[l] < nums[r]){
            return r;
        }

    }
};