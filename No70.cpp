class Solution {
public:
    int climbStairs(int n) 
    {
    	if(n==0)
    	{
    		return 0;
    	}
    	if(n==1)
    	{
    		return 1;
    	}
    	
    	int uniquePathNum[n];
    	uniquePathNum[0]=1;
    	uniquePathNum[1]=2;
    	for(int i=2; i<n; i++)
    	{
    		uniquePathNum[i]=uniquePathNum[i-1]+uniquePathNum[i-2];
    	}    
    	return uniquePathNum[n-1];
    }
};