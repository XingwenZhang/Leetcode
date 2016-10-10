class Solution {
public:
    int maxArea(vector<int>& height) 
    {
    	int i,j;
    	i=0; 
    	j=height.size()-1;
    	int h;
    	int result=0;
    	while(i<j)
    	{
    		h=min(height[i],height[j]);
    		result=max(result,(j-i)*h);
    		while(i<j && height[i]<=h) i++;
    		while(i<j && height[j]<=h) j--;
    	}  
    	return result;  
    }
};