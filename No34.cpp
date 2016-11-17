/*//this is my first solution, not so elegent
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
    	int len = nums.size();
    	int index = binarySearch(nums,0,len-1,target);
    	vector<int> ans;
    	if(index==-1)
    	{
    		ans.push_back(-1);
    		ans.push_back(-1);
    		return ans;
    	}
    	int indexLeft=index;
    	int indexRight=index;
    	while(indexRight<len)
    	{
    		indexRight++;
    		if(nums[indexRight]!=target)
    		{
    			break;
    		}
    	}
    	if(nums[0]==target)
    	{
    		ans.push_back(0);
    		
    		ans.push_back(indexRight-1);
    		return ans;
    	}
    	else
    	{
    		while(indexLeft>0)
    		{
    			indexLeft--;
    			if(nums[indexLeft]!=target)
    			{
    				break;
    			}
    		}
    		ans.push_back(indexLeft+1);
    		ans.push_back(indexRight-1);
    		return ans;
    	}

    }
public:

	//binarySearch
	int binarySearch(vector<int>& nums, int start, int end, int target)
	{
		if(start>end)
		{
			return -1;
		}
		int mid = (start+end)/2;

		if(nums[mid]==target)
		{
			return mid;
		}
		else if(nums[mid]<target)
		{
			return binarySearch(nums,mid+1,end,target);
		}
		else
		{
			return binarySearch(nums,start,mid-1,target);
		}
	}
};*/

//second method, double binary search
//however, I think these two method, their time complexity is similar
//even the first one is quicker
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        vector<int> ans(2,-1);
        //find the leftmost index
        while(start<end)
        {
        	int mid = (start+end)/2;
        	if(target > nums[mid])
        	{
        		start = mid+1;
        	}
        	else
        	{
        		end = mid;
        	}
        }
        if(nums[start]!=target)
        {
        	return ans;
        }
        ans[0]=start;

        end = nums.size()-1;
        while(start<end)
        {
        	//if not +1, then no end loop
        	//[2,2] target 2
        	//every loop the start is 0, no update
        	//so need to make mid right
        	int mid = (start+end)/2+1;
        	if(target < nums[mid])
        	{
        		end = mid-1;
        	}
        	else
        	{
        		start = mid;
        	}
        }
        ans[1]=end;
        return ans;
    }
};