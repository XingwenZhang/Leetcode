class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) 
    {
    	sudokuHelper(board);
    }
private:
	bool usedInRow(int num, int rowNum, vector<vector<char>>& board)
	{
		vector<char> rowEle = board[rowNum];
		for(auto i:rowEle)
		{
			if(num == i-'0')
			{
				return true;
			}
		}
		return false;
	}

	bool usedInCol(int num, int colNum, vector<vector<char>>& board)
	{
		int size = board.size();
		for(int i=0; i<size; i++)
		{
			if(num == board[i][colNum]-'0')
			{
				return true;
			}
		}
		return false;
	}

	bool usedInCell(int num, int cellRow, int cellCol, vector<vector<char>>& board)
	{
		for(int i=cellRow; i<cellRow+3; i++)
		{
			for(int j=cellCol; j<cellCol+3; j++)
			{
				if(num == board[i][j]-'0')
				{
					return true;
				}
			}
		}
		return false;
	}

	bool isSafe(int num, int locRow, int locCol, vector<vector<char>>& board)
	{
		return (!usedInRow(num,locRow,board) &&
			!usedInCol(num,locCol,board) &&
			!usedInCell(num,int(locRow/3)*3,int(locCol/3)*3,board));
	}

	bool isComplete(vector<vector<char>>& board, int& i, int& j)
	{
		int rowNum = board.size();
		int colNum = board[0].size();
		for(i=0; i<rowNum; i++)
			for(j=0; j<colNum; j++)
			{
				if(board[i][j]=='.')
					return false;
			}
		return true;
	}

	bool sudokuHelper(vector<vector<char>>& board)
	{
		int rowNum=0,colNum=0;
		if(isComplete(board,rowNum,colNum))
		{
			return true;
		}

		for(int i=1; i<10; i++)
		{
			if(isSafe(i,rowNum,colNum,board))
			{
				board[rowNum][colNum]=i+'0';
				if(sudokuHelper(board))
				{
					return true;
				}
				board[rowNum][colNum]='.';
			}
		}
		return false;		
	}
};