class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
    	//int isCheck[10][10];
    	//memset(isCheck,0,sizeof(isCheck)/sizeof(int));
    	vector<int> isCheck(10,0);
    	int rowNum = board.size();
    	if(rowNum!=9)
    	{
    		return false;
    	}

    	//check per row
    	for(int i=0; i<rowNum; i++)
    	{
    		if(board[i].size()!=9)
    		{
    			return false;
    		}
    		for(int j=0; j<9; j++)
    		{
    			if(board[i][j]=='.')
    			{
    				isCheck[0]++;
    			}
    			else
    			{
    				isCheck[board[i][j]-'0']++;
    			}
    		}
    		for(int k=1; k<10; k++)
    		{
    			if(isCheck[k]>1)
    			{
    				return false;
    			}
    		}
    		isCheck.assign(10,0);
    	}

    	//check per column
    	for(int j=0; j<9; j++)
    	{
    		for(int i=0; i<9; i++)
    		{
    			if(board[i][j]=='.')
    			{
    				isCheck[0]++;
    			}
    			else
    			{
    				isCheck[board[i][j]-'0']++;
    			}
    		}
    		for(int k=1; k<10; k++)
    		{
    			if(isCheck[k]>1)
    			{
    				return false;
    			}
    		}
    		isCheck.assign(10,0);
    	}


    	//check per cell
    	int m=0; int n=0;
    	while(n!=9)
    	{
    		for(int i=m; i<m+3; i++)
    		{
    			for(int j=n; j<n+3; j++)
    			{
    				if(board[i][j]=='.')
    				{
    					isCheck[0]++;
    				}
    				else
    				{
    					isCheck[board[i][j]-'0']++;
    				}
    			}
    		}
    		for(int k=1; k<10; k++)
    		{
    			if(isCheck[k]>1)
    			{
    				return false;
    			}
    		}
    		isCheck.assign(10,0);
    		m+=3;
    		if(m==9)
    		{
    			m=0;
    			n+=3;
    		}
    	}


    	return true;



    }

};