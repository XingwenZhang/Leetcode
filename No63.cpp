class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
    	int rowNum = obstacleGrid.size();
    	int columnNum = obstacleGrid[0].size();

    	int uniquePathNum[rowNum][columnNum];
    	int i,j;

    	//initial need to pay attention to 
    	//if there is an obstacle in the first row or column
    	//then the rest of initial must be 0
    	for(i=0; i<rowNum; i++)
    	{
    		if(obstacleGrid[i][0]==0)
    		{
    			uniquePathNum[i][0]=1;
    		}
    		else
    		{
    			uniquePathNum[i][0]=0;
    			break;
    		}
    	}    
    	while(i<rowNum)
    	{
    		uniquePathNum[i++][0]=0;
    	}

    	for(j=0; j<columnNum; j++)
    	{
    		if(obstacleGrid[0][j]==0)
    		{
    			uniquePathNum[0][j]=1;
    		}
    		else
    		{
    			uniquePathNum[0][j]=0;
    			break;
    		}
    	}
    	while(j<columnNum)
    	{
    		uniquePathNum[0][j++]=0;
    	}

    	for(i=1; i<rowNum; i++)
    	{
    		for(j=1; j<columnNum; j++)
    		{
    			if(obstacleGrid[i][j]==1)
    			{
    				uniquePathNum[i][j]=0;
    			}
    			else
    			{
    				uniquePathNum[i][j]=uniquePathNum[i-1][j]+uniquePathNum[i][j-1];
    			}
    		}
    	}

    	return uniquePathNum[rowNum-1][columnNum-1];
    }
};