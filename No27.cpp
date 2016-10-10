class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
    	int valTime = 0;
    	int i = 0;
    	int j = nums.size()-1;
    	//i<=j rather than i<j, for the situation [1] 1 .
    	
    	while((i<=j)&&(j>=0))
    	{
    		if(nums[j]!=val)
    		{
    			//i<j so i will stop if it meets j
    			while((nums[i]!=val)&&(i<j))
    			{
    				i++;
    			}
    			//if i meets j, just stop
    			if(i>=j)
    			{
    				break;
    			}
    			
    			swap(nums[i],nums[j]);
    			valTime++;
    			j--;
    			
    		}
    		else
    		{
    			valTime++;
    			j--;
    		}
    	}
    	return nums.size()-valTime;    
    }
};