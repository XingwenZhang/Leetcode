class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
    	int x=nums[0],i,len=nums.size();
    	//i should be initiated 1 rather 0. take [1] for example
    	for(i=1;i<len;i++)
    	{
    		x^=nums[i];
    	}
    	return x;

    }
};