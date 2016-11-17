class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
    	return binarySearch(nums,0,nums.size()-1,target);
    	    
    }
private:
	int binarySearch(vector<int>& nums, int start, int end, int target)
	{
		//because everytime the update distance is only 1
		//so actually the trigger for this if is just ==
		if(start >= end)
		{
			if(target == nums[start])
				return start;
			if(target > nums[start])
				return start+1;
			else
				return start;
		}
		int mid = (start+end)/2;
		if(target == nums[mid])
		{
			return mid;
		}
		else if(target > nums[mid])
		{
			return binarySearch(nums,mid+1,end,target);
		}
		else
		{
			return binarySearch(nums,start, mid-1, target);
				
		}
	}
};