class Solution {
public:
bool isValidSudoku(vector<vector<char> >& board)
{
	for (int i = 0; i < 9; ++i)
		if(!isValid(board, i, 0, i, 8) || !isValid(board, 0, i, 8, i))
		  return false;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
		{
			if (!(isValid(board, i * 3, j * 3, i * 3 + 2, j * 3 + 2)))
				return false;
		}
	return true;
}

bool isValid(vector<vector<char> > &board, int s, int b, int m, int n)
{
	bool flag[9] = {false};
	for (int i = s; i <= m; ++i)
		for (int j = b; j <= n; ++j)
		{
			if (board[i][j]!= '.')
			{
				int t = board[i][j] - '1';
				if (flag[t]) return false;
				flag[t] = true;
			}
		}
		return true;
}
};
