// 287. Find the Duplicate Number

// Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

// Note:
// You must not modify the array (assume the array is read only).
// You must use only constant, O(1) extra space.
// Your runtime complexity should be less than O(n2).
// There is only one duplicate number in the array, but it could be repeated more than once.
// Credits:
// Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.


class Solution {
public:
    // If the array could be modified
    int findDuplicate(vector<int>& nums) {
        for(auto item : nums){
            if(nums[abs(item)] < 0){
                return abs(item);
            }
            else{
                nums[abs(item)] *= -1;
            }
        }

        return -1;
    }
};


class Solution {
public:
    // Now array cannot be modified, and O(1) space, less than O(n^2) complexity
    int findDuplicate(vector<int>& nums) {
        // Binary Search O(nlogn)

        int low = 1, high = nums.size() - 1;

        while(low < high){
            int mid = low + 1/2 * (high - low);
            int cnt = 0;
            for(auto item : nums){
                if(item <= mid) ++cnt;
            }
            if(cnt <= mid) low = mid + 1;
            else high = mid;
        }

        return low;
    }
};


class Solution {
public:
    // another method inspired by double pointers to find the cycle in linkedlist
    int findDuplicate(vector<int>& nums) {
        int fast = 0, slow = 0, finder = 0;

        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }

        while(true){
            slow = nums[slow];
            finder = nums[finder];
            if(slow == finder) break;
        }

        return finder;
    }
};


