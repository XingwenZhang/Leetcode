class Solution {
public:
    int rob(vector<int>& nums) 
    {

    	int len=nums.size();

    	//corner-case
    	if(len==0)
    	{
    		return 0;
    	}
    	if(len==1)
    	{
    		return nums[0];
    	}
    	if(len==2)
    	{
    		return max(nums[0],nums[1]);
    	}

    	//if rob 1 then no rob n
    	//if rob n then no rob 1

    	//rob 1
    	int opt1[len];
    	opt1[0]=0;
    	opt1[1]=nums[0];
    	opt1[2]=nums[0];
    	for(int i=3; i<len; i++)
    	{
    		opt1[i]=max(opt1[i-1],opt1[i-2]+nums[i-1]);
    	}

    	//rob n
    	int opt2[len+1];
    	opt2[0]=0;
    	opt2[1]=0;
    	opt2[2]=nums[1];
    	for(int i=3; i<len+1; i++)
    	{
    		opt2[i]=max(opt2[i-1],opt2[i-2]+nums[i-1]);
    	}

    	return max(opt1[len-1],opt2[len]);
    }
};