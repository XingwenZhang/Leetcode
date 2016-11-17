class Solution {
public:
    int trap(vector<int>& height)
    {
    	int len = height.size();
    	if(len==0||len==1)
    	{
    		return 0;
    	}
    	vector<int>left(len,-1);
    	vector<int>right(len,-1);
    	int water=0;
    	left[0]=height[0];
    	right[len-1]=height[len-1];

    	for(int i=1; i<len; i++)
    	{
    		left[i]=max(left[i-1],height[i]);
    	}

    	for(int j=len-2; j>=0; j--)
    	{
    		right[j]=max(right[j+1],height[j]);
    	}
    	for(int k=0; k<len; k++)
    	{
    		water+=min(left[k],right[k])-height[k];
    	}
    	return water;

    }
};	