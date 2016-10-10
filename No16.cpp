class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
    	int minError=INT_MAX;
    	int sum = 0;
    	int tempsum=0;
    	int len = nums.size();
    	sort(nums.begin(),nums.end());
    	for(int i=0; i<len-2; i++)
    	{
    		if(i&&nums[i]==nums[i-1])
    		{
    			continue;
    		}
    		int j=i+1; 
    		int k=len-1;
    		while(j<k)
    		{
    			if(j!=i+1 && nums[j]==nums[j-1])
    			{
    				j++;
    				continue;
    			}
    			if(k!=len-1 && nums[k]==nums[k+1])
    			{
    				k--;
    				continue;
    			}
    			tempsum = nums[i]+nums[j]+nums[k];

    			//abs for the negative situation
    			if(abs(tempsum-target)<minError)
    			{
    				minError=abs(tempsum-target);
    				sum = tempsum;
    			}
    			if(nums[j]+nums[k]>target-nums[i])
    			{
    				k--;
    			}
    			else if(nums[j]+nums[k]<target-nums[i])
    			{
    				j++;
    			}
    			//once equal, just break, the error has already been minus
    			else
    			{
    				break;
    			}
    		}
    	}  

    	return sum;  
    }
};