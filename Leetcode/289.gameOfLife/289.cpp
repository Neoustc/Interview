 //Since the board has ints but only the 1-bit is used, I use the 2-bit to store the new state
 void gameOfLife(vector<vector<int> >& board) 
 {
 	int m = board.size();
 	int n = m ? board[0].size() : 0;
 	int dir[8][2] = {{-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}};
 	for (int i = 0; i < m; ++i)
 		for (int j = 0; j < n; ++j)
 		{
 			count = 0;
 			for (int d = 0; d < 8; d++)
 			{
 				int x = i + dir[d];
 				int y = j + dir[d];
 				if ( 0 <= x && x < m && 0 <= y && y < n )
 				count += board[x][y] & 1;
 			}
 			if ((board[i][j] && 2 <= count && count <= 3) || (count == 3 && !board[i][j]))
 			board[i][j] |= 2;
 		}
 	for (int i = 0; i < m; ++i)
 		for (int j = 0; j < n; ++j)
 		{
 			board[i][j] >>= 1;
 		}
 }
