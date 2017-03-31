// Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

// The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

// You may assume that each input would have exactly one solution and you may not use the same element twice.

// Input: numbers={2, 7, 11, 15}, target=9
// Output: index1=1, index2=2


class Solution {
public:
	// Two pointers, one from head to tail, one from tail to head
    vector<int> twoSum(vector<int>& numbers, int target) {
        int index1=0, index2 = numbers.size()-1;
        vector<int> res;
        while(index1 < index2){
        	if(numbers[index1] + numbers[index2] == target){
        		res.push_back(index1+1);
        		res.push_back(index2+1);
        		break;
        	}
        	// Sum is greater than target
        	// need to reduce the sum
        	else if(numbers[index1] + numbers[index2] > target){
        		index2--;
        	}
        	// Sum is less than target
        	else{
        		index1++;
        	}
        }
        return res;
    }
};