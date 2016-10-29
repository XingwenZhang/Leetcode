class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
    	int rowNum = grid.size();
    	int columnNum = grid[0].size();
    	int pathSum[rowNum][columnNum];
    	pathSum[0][0]=grid[0][0];
    	for(int i=1; i<rowNum; i++)
    	{
    		pathSum[i][0]=pathSum[i-1][0]+grid[i][0];
    	}    
    	for(int j=1; j<columnNum; j++)
    	{
    		pathSum[0][j]=pathSum[0][j-1]+grid[0][j];
    	}

    	for(int i=1; i<rowNum; i++)
    	{
    		for(int j=1; j<columnNum; j++)
    		{
    			pathSum[i][j]=min(pathSum[i][j-1],pathSum[i-1][j])+grid[i][j];
    		}
    	}
    	return pathSum[rowNum-1][columnNum-1];
    }
};