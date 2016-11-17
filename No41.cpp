class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
    	if(nums.size()==0)
    	{
    		return 1;
    	}
    	int loc = split(nums);
    	return findMissingPos(nums,loc+1);

    }
private:
	//return the last pos num location
	int split(vector<int>& nums)
	{
		int start = 0;
		int end = nums.size()-1;
		while(start<=end)
		{
			if(nums[start]<=0 && nums[end]>0)
			{
				swap(nums[start],nums[end]);
				start++;
				end--;
			}
			else if(nums[start]<=0 && nums[end]<=0)
			{
				end--;
			}
			else if(nums[start]>0 && nums[end]>0)
			{
				start++;
			}
			else if(nums[start]>0 && nums[end]<=0)
			{
				start++;
				end--;
			}
		}
		return end;
	}

	//len is the lenght of the pos number
	int findMissingPos(vector<int>& nums, int len)
	{
		
		for(int i=0; i<len; i++)
		{
			if(abs(nums[i])-1<len && nums[abs(nums[i])-1]>0)
			{
				nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
			}
		}
		for(int i=0; i<len; i++)
		{
			if(nums[i]>0)
			{
				return i+1;
			}
		}
		return len+1;
	}
};