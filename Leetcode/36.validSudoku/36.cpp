class Solution {
public:
bool isValidSudoku(vector<vector<char> >& board)
{
	bool h[9][9] = {false};
	bool v[9][9] = {false};
	bool s[9][9] = {false};
	int i = 0, j = 0;
	for (i = 0; i < 9; ++i)
		for (j = 0; j < 9; ++j)
		{
			if (board[i][j] != '.')
			{
				int t = board[i][j] - '1';
				if (h[i][t])  return false;
				h[i][t] = true;
				if (v[j][t])  return false;
				v[j][t] = true;
				if (s[i / 3 * 3 + j / 3][t]) return false;
				s[i / 3 * 3 + j / 3][t] = true;
			}
		}
return true;
}
};
