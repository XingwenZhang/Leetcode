/*238. Product of Array Except Self

Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)*/


// two array, one for the accumulative product from left to right, another for product from right to left
// time complexity n, space complexity n
/*class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    	int len = nums.size();
    	int LR[len];
    	int RL[len];
    	for(int i=0; i<len; i++){
    		LR[i] = 1;
    		RL[i] = 1;
    	}
    	LR[0] = nums[0];
    	RL[len-1] = nums[len-1];
    	for(int i=1; i<len; i++){
    		LR[i] = LR[i-1] * nums[i];
    	}
    	for(int j=len-2; j>=0; j--){
    		RL[j] = RL[j+1] * nums[j];
    	}
        int res[len];
        res[0] = RL[1];
        res[len-1] = LR[len-2];

        for(int k=1; k<len-1; k++){
        	res[k] = LR[k-1]*RL[k+1];
        }
        return vector<int>(res,res+len);
    }
};
*/


// same idea, but concise code
/*class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

    	int len = nums.size();
    	//from left to right
        vector<int> LR(len);
        //from right to left
        vector<int> RL(len);
        LR[0] = 1;
        RL[0] = 1;

        for(int i=1; i<len; i++)
        {
        	LR[i] = LR[i-1] * nums[i-1];
        	RL[i] = RL[i-1] * nums[len-i];
        }

        vector<int> res(len);
        for(int i=0; i<len; i++)
        {
        	res[i] = LR[i] * RL[len-i-1];
        }
        return res;
    }
};*/

// same idea, but O(1) space complexity
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        int LR = 1;
        int RL = 1;
        vector<int> res(len,1);

        for(int i=0; i<len; i++){
        	res[i] *= LR;
        	LR *= nums[i];
        	res[len-i-1] *= RL;
        	RL *= nums[len-i-1];
        }

        return res;
    }
};