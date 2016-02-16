 int minPathSum(vector<vector< int> > & grid)
    {
    int m = grid.size(), n = m ? grid[0].size() : 0;
  	vector<int> cur (m, grid[0][0]);
  	for (int i = 1; i < m; ++i)
  		cur[i] = cur[i - 1] + grid[i][0];
  	for (int j = 1; j < n; ++j)
  	{
  		cur[0] += grid[0][j];
  		for (int i = 1; i < m; ++i)
  			cur[i] = min(cur[i], cur[i - 1]) + grid[i][j];
  	}
  	return cur[m - 1];
    }
