class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
    	vector<vector<int>>ans;
    	int len = nums.size();
    	if(len==0)
    	{
    		return ans;
    	}

    	//sort nums to ascending order
    	sort(nums.begin(),nums.end());

    	ans.push_back(nums);

    	//if return false, means all permutations have been collected
    	while(nextPermutation(nums))
    	{
    		ans.push_back(nums);
    	}
    	return ans;
        
    }
private:

	//see leetcode No.31
	//https://leetcode.com/problems/next-permutation/
	bool nextPermutation(vector<int>& nums)
	{
		int len = nums.size();
		if(len==0||len==1)
		{
			return false;
		}

		int i,j;
		i=len-1;
		while(true)
		{
			j=i;
			i--;
			if(nums[i]<nums[j])
			{
				int k = len-1;
				while(!(nums[i]<nums[k]))
				{
					k--;
				}
				swap(nums[i],nums[k]);
				reverse(nums.begin()+j,nums.end());
				return true;
			}
			if(i==0)
			{
				reverse(nums.begin(),nums.end());
				return false;
			}
		}
	}
};