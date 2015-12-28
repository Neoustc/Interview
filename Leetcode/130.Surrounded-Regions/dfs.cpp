// dfs might overflow;
OOOOOOOOOXX
XXXXXXXXOXX
XXOOOOOOOXX
XXOXXXXXXXX
XXOOOOOOOXX
------------------------
class Solution {
public:
    void solve(vector<vector<char> >& board) {
        int m = board.size();
        int n = m ? board[0].size() : 0;
        if (m <= 2 || n <= 2) return;
        vector<vector<bool> > visited(m, vector<bool>(n, 0));
        for (int i = 0; i < m; ++i)      	
        {
        	if (board[i][0] == 'O' && !visited[i][0])
        	 {
        	    visited[i][0] = 1;
        	 	dfs(board, visited, m, n, i, 0);
        	 }
        	if (board[i][n - 1] == 'O' && !visited[i][n - 1])
        	 {
        	    visited[i][n - 1] = 1;
        	 	dfs(board, visited, m, n, i, n - 1);
        	 }
        }
         //cout<<"sss"<<endl;
        // cout<<n<<endl;
        for (int i = 0; i < n; ++i) 
        {
            cout<< i<<endl;
        	if (board[0][i] == 'O' && !visited[0][i])
        	 {
        	    visited[0][i] = 1;
        	 	dfs(board, visited, m, n, 0, i);
        	 }
        	if (board[m - 1][i] == 'O' && !visited[m - 1][i])
        	 {
        	     visited[m - 1][i] = 1;
        	 	dfs(board, visited, m, n, m - 1, i);
        	 }
       } 
        for (int i = 0; i < m; ++i)
        	for (int j = 0; j < n; ++j)
        	{
        	    if (board[i][j] == 'O')
        		    board[i][j] = 'X';
        		else if (board[i][j] == '+')
        			board[i][j] = 'O';
        		
        	}
        	return;
    }
    void dfs(vector<vector<char> > & board, vector<vector<bool> >& visited, int m, int n, int x, int y)
    {	
    	board[x][y] = '+';
    	int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1,0}};
    	int p = x, q = y;
    	for (int i = 0; i < 4; ++i)
    	{
    		p = x + dir[i][0];
    		q = y + dir[i][1];
    		if ( 0 < p && p < m - 1 && 0 < q && q < n - 1 && board[p][q] == 'O' && !visited[p][q])
    		    {
    		        visited[p][q] = 1;
    		    	dfs(board, visited, m, n, p, q);
    		    }
    	}
    	return;
    }
};
