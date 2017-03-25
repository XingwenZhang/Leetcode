// Follow up for "Remove Duplicates":
// What if duplicates are allowed at most twice?

// For example,
// Given sorted array nums = [1,1,1,2,2,3],

// Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.


class Solution {
public:

	// In place swap
    int removeDuplicates(vector<int>& nums) {
        
        int len = 0;

        nums.push_back(INT_MAX);

        // To remember the number of duplicates
        int dup = 1;

        for(int i = 0; i < nums.size()-1; i++){
        	if((nums[i] != nums[i+1]) && (dup <= 2)){
        		len++;
        		dup = 1;
        		if(len-1 != i){
        			swap(nums[i], nums[len-1]);
        		}
        	}
        	else if((nums[i] != nums[i+1]) && (dup > 2)){
        		dup = 1;
        	}
        	if((nums[i] == nums[i+1]) && (dup <= 2)){
        		len++;
        		dup++;
        		if(len-1 != i){
        			swap(nums[i], nums[len-1]);
        		}
        	}
        }
        return len;
    }
};