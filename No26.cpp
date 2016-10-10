class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
    	int len=0;
    	nums.push_back(INT_MAX);
    	for(int i=0; i<nums.size()-1; i++)
    	{
    		if(nums[i]!=nums[i+1])
    		{
    			len++;
    			if(len-1!=i)
    			{
    			    swap(nums[i],nums[len-1]);
    			}
    		}
    	}    
    	return len;

    }
};