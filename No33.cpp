class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
    	int len = nums.size();
    	int indexPivot = findPivot(nums,0,len-1);
    	int left=binarySearch(nums,0,indexPivot);
    	int right=binarySearch(nums,indexPivot+1,len-1,target);
    	if(left==-1&&right==-1)
    	{
    		return -1;
    	}
    	else
    	{
    		return left+right+1;
    	}

    }
private:
	//find pivot number's index
	//pivot is the only which is bigger than its next num
	int findPivot(vector<int>& nums, int start, int end)
	{
		if(start>end)
		{
			return -1;
		}
		if(start == end)
		{
			return start;
		}
		int mid = (start+end)/2;
		//find pivot
		if(mid<end && nums[mid]>nums[mid+1])
		{
			return mid;
		}
		//find pivot's next location
		if(mid>start && nums[mid]<nums[mid-1])
		{
			return mid-1;
		}
		if(nums[mid]<=nums[start])
		{
			return findPivot(nums,start,mid-1);
		}
		else
		{
			return findPivot(nums,mid+1,end);
		}
	}

	//binarySearch
	int binarySearch(vector<int>& nums, int start, int end, int value)
	{
		if(start > end)
		{
			return -1;
		}
		int mid = (start+end)/2;

		if(value == nums[mid])
		{
			return mid;
		}
		else if(value < nums[mid])
		{
			return binarySearch(nums,start,mid-1,value);
		}
		else
		{
			return binarySearch(nums,mid+1,end, value);
		}


	}
};