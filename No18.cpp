class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
    	vector<int> temp;
    	vector<vector<int> >result;
    	int len = nums.size();
    	//corner-case
    	if(len<4)
    	{
    		return result;
    	}    

    	sort(nums.begin(),nums.end());

    	for(int i=0; i<len-3; i++)
    	{
    		//these two to improve the efficiency
    		if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target)
    			break;

    		if(nums[i]+nums[len-1]+nums[len-2]+nums[len-3]<target)
    			continue;


    		if(i && nums[i]==nums[i-1])
    		{
    			continue;
    		}
    		for(int j=i+1; j<len-2; j++)
    		{
    			//these two to improve the efficiency
    			if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target)
    				break;
    			if(nums[i]+nums[j]+nums[len-1]+nums[len-2]<target)
    				continue;


    			if(j!=i+1 && nums[j]==nums[j-1])
    			{
    				continue;
    			}
    			int m=j+1;
    			int n=len-1;
    			while(m<n)
    			{
    				if(m!=j+1 && nums[m]==nums[m-1])
    				{
    					m++;
    					continue;
    				}
    				if(n!=len-1 && nums[n]==nums[n+1])
    				{
    					n--;
    					continue;
    				}
    				if(nums[i]+nums[j]+nums[m]+nums[n]==target)
    				{
    					temp.push_back(nums[i]);
    					temp.push_back(nums[j]);
    					temp.push_back(nums[m]);
    					temp.push_back(nums[n]);
    					result.push_back(temp);
    					temp.clear();
    					m++;
    					n--;
    				}
    				else if(nums[i]+nums[j]+nums[m]+nums[n]>target)
    				{
    					n--;

    				}
    				else 
    				{
    					m++;
    				}


    			}
    		}
    	}

    	return result;
    }
};