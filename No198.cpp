class Solution {
public:
    int rob(vector<int>& nums) 
    {
        if(nums.size()==0)
        {
            return 0;
        }
        if(nums.size()==1)
        {
            return nums[0];
        }
        
    	int len = nums.size();
    	int opt[len+1];
    	opt[0]=0;
    	opt[1]=nums[0];
    	opt[2]=max(nums[0],nums[1]);

    	for(int i=3; i<len+1; i++)
    	{
    		opt[i]=max(opt[i-1],opt[i-2]+nums[i-1]);
    	}
    	return opt[len];
    }
};