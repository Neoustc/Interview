// BFS and don't need visted auxiliary vector.
class Solution {
private :
	int dir[4][2] = {{1, 0},{-1, 0}, {0, 1}, {0, -1}};
public:
    void solve(vector<vector<char> >& board) 
    {
       int m = board.size();
       int n = m ? board[0].size() : 0; 
       if (m <= 2 || n <= 2) return;
       for (int i = 0; i < n; ++i)
       {
       	if (board[0][i] == 'O')
       		bfs(board, m, n, 0, i);
       	if (board[m - 1][i] == 'O')
       		bfs(board, m, n, m - 1, i);
       }
       for (int i = 0; i < m; ++i)
       {
       	if (board[i][0] == 'O')
       		bfs(board, m, n, i, 0);
       	if (board[i][n - 1] == 'O')
       		bfs(board, m, n, i, n - 1);
       }
       for (int i = 0; i < m; ++i)
       	 for (int j = 0; j < n; ++j)
       	 {
       	 	if (board[i][j] == 'O')
       	 		board[i][j] = 'X';
       	 	else if (board[i][j] == '+')
       	 		board[i][j] = 'O';
       	 }
   }
   void bfs(vector<vector<char> >& board, int m, int n, int x, int y)
   {
   	queue<pair<int, int> > que;
   	que.push(make_pair(x, y));
   	board[x][y] = '+';
   	while(!que.empty())
   	{
   	pair<int, int> cur = que.front();
   	que.pop();
   	for (int i = 0; i < 4; i++)
    	{
    		int px = cur.first + dir[i][0];
    		int py = cur.second + dir[i][1];
    		if (!(px < 0 || px >= m || py < 0 || py >= n))
    		{
    			if (board[px][py] == 'O')
    			{
    				que.push(make_pair(px, py));
    				board[px][py] = '+';
    			}
    		}
   		}
   }
   }
};
