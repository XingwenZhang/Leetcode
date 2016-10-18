class Solution {
public:
    int uniquePaths(int m, int n) 
    {
    	//m is the number of row
    	//n is the number of column
    	int uniquePathNum[m][n];
    	for(int i=0; i<m; i++)
    	{
    		uniquePathNum[i][0]=1;
    	}    
    	for(int j=0; j<n; j++)
    	{
    		uniquePathNum[0][j]=1;
    	}
    	for(int i=1; i<m; i++)
    	{
    		for(int j=1; j<n; j++)
    		{
    			uniquePathNum[i][j]=uniquePathNum[i-1][j]+uniquePathNum[i][j-1];
    		}
    	}
    	return uniquePathNum[m-1][n-1];
    }
};