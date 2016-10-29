class Solution {
public:
	int maxSubArray(vector<int>& nums) 
	{
		bool flag = true;
		int max=INT_MIN;
		for(int i=0; i<nums.size(); i++)
		{
			if(nums[i]>0)
			{
				flag=false;
				break;
			}
			else
			{
				if(nums[i]>max)
					max = nums[i];

			}
		}
		if(!flag)
		{
			int max_end=0;
			int max_here = 0;
			for(int i=0; i<nums.size(); i++)
			{
				max_here=max_here+nums[i];
				if(max_here<0)
				{
					max_here=0;
				}
				else if(max_here > max_end)
				{
					max_end=max_here;
				}
			}
			return max_end;
		}
		else
		{
			return max;
		}

	}
};


