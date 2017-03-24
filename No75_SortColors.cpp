// Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

// Note:
// You are not suppose to use the library's sort function for this problem.

// click to show follow up.


class Solution {
public:

	// One-pass and constant space
	// Bubble sort is in-place sorting, however time complexity is O(n^2)

	// For this problem, it only have three values, so double pointers, one from
	// the beginning, one from the ending.
	
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int index0 = 0, index2 = len-1;

        for(int i = 0; i <= index2; i++){
        	// Here use while
        	// if the num of position index2 is 2 itself
        	while(nums[i] == 2 && i < index2){
        		swap(nums[i], nums[index2]);
        		index2--;
        	}
        	// Here no need while
        	// Because the value in index0 cannot be 0
        	// Because i has already traversed the index0
        	if(nums[i] == 0 && i >= index0){
        		swap(nums[i], nums[index0]);
        		index0++;
        	}

        }
    }
};


        // while(left <= right){
        // 	// if(nums[left] == 0){
        // 	// 	left++;
        // 	// 	index0++;
        // 	// }
        // 	// if(nums[right] == 2){
        // 	// 	right--;
        // 	// 	index2--;
        // 	// }

        // 	// If exchange the value
        // 	if(nums[left] == 2 && nums[right] == 0){
        // 		if(left == index0 && right == index2){
        // 			swap(nums[left], nums[right]);
        // 		}
        // 		else{
        // 			swap(nums[left], nums[index2]);
        // 			swap(nums[right], nums[index0]);
        // 		}
        // 		// swap(nums[left], nums[]);
        // 		left++;
        // 		right--;
        // 		index0++;
        // 		index2--;
        // 		continue;
        // 	}

        // 	if(nums[left] == 0 && nums[right] == 2){
        // 		if(left != index0){
        // 			swap(nums[left], nums[index0]);
        // 			index0++;
        // 		}
        // 		if(right != index2){
        // 			swap(nums[right], nums[index2]);
        // 			index2--;
        // 		}
        // 		left++;
        // 		right--;
        // 	}
        // 	// If nums[left] is 0, but nums[right] is 1
        // 	if(nums[left] == 0){
        // 		left++;
        // 		//index0++;
        // 		continue;
        // 	}

        // 	if(nums[left] == 2){
        // 		swap(nums[left], nums[index2]);
        // 		left++;
        // 		index2--;
        // 		continue;
        // 	}

        // 	if(nums[right] == 2){
        // 		right--;
        // 		//index2--;
        // 		continue;
        // 	}

        // 	if(nums[right] == 0){
        // 		swap(nums[right], nums[index0]);
        // 		right--;
        // 		index0++;
        // 		continue;
        // 	}

        // 	if(nums[left] == 1 && nums[right] == 1){
        // 		left++;
        // 		right--;
        // 	}
//         // }
//     }
// };