class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string> > ans;
		string temp;
		for (int i = 0; i < n; i++)
		{
			temp += '.';
		}
		vector<string> board(n, temp);
		map<vector<string>, int> checkDuplicate;
		
		nQueensHelper(board, ans, checkDuplicate, 0, n);
		return ans;
	}
private:

	//because the Queen is arranged col by col. 
	//So no need check the diff col
	//no need check the right side diaganal
	bool isSafe(vector<string>& board, int row, int col, int n)
	{
		//check if used in one row
		for (int i = 0; i<n; i++)
		{
			if (board[row][i] == 'Q')
			{
				return false;
			}
		}

		for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
		{
			if (board[i][j] == 'Q')
			{
				return false;
			}
		}

		for (int i = row, j = col; i<n && j >= 0; i++, j--)
		{
			if (board[i][j] == 'Q')
			{
				return false;
			}
		}
		return true;
	}

	bool nQueensHelper(vector<string>& board, vector<vector<string> >& ans, map<vector<string>, int>& checkDuplicate, int col, int n)
	{
		if (col >= n)
		{
			//ans.push_back(board);
			return true;
		}
		for (int i = 0; i<n; i++)
		{
			if (isSafe(board, i, col, n))
			{
				board[i][col] = 'Q';
				if (nQueensHelper(board, ans, checkDuplicate, col + 1, n))
				{
					if (checkDuplicate[board] == 0)
					{
						checkDuplicate[board] = 1;
						ans.push_back(board);
					}
				}
				//backtracking
				board[i][col] = '.';
			}
		}

		//trigger for backtracking
		return false;
	}
};