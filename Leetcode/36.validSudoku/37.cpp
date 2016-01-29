class Solution {
public:
   void solveSudoku (vector<vector<char> >& board) {
 		bool h[9][9] = {false};
 		bool v[9][9] = {false};
 		bool s[9][9] = {false};
 		for (int i = 0; i < 9; ++i)
 			for (int j = 0; j < 9; ++j)
 			{
 				if (board[i][j] != '.')
 					{
 						int t = board[i][j] - '1';
 						h[i][t] = true;
 						v[j][t] = true;
 						s[i / 3 * 3 + j / 3][t] = true;
 					}

 			}
        fillboard(board, h, v, s, 0, 0);
    }
 bool fillboard (vector<vector<char> > & board, bool (&h)[9][9], bool (&v)[9][9], bool (&s)[9][9], int row, int col)
 {
 	
    if (row == 9) return true;
    if (col == 9) return fillboard(board, h, v, s, row + 1, 0); 
    if(board[row][col]!='.') return fillboard(board,h,v,s,row,col + 1);
	
	if (board[row][col] == '.')
		 	{
		 		for (int i = 1; i <= 9; ++i)
		 		{
		 			if (!h[row][i - 1] && !v[col][i - 1] && !s[row / 3 * 3 + col / 3][i - 1])
		 				{
		 				board[row][col] = (i + '0');
		 				h[row][i - 1] = v[col][i - 1] = s[row / 3 * 3 + col / 3][i - 1] = true;
		 			    if (fillboard(board, h, v, s, row, col + 1)) return true;
		 			    h[row][i - 1] = v[col][i - 1] = s[row / 3 * 3 + col / 3][i - 1] = false;
		 			    board[row][col] = '.';
		 				}
		 		}
                return false;
		 	}
 	return false;
 }



};
