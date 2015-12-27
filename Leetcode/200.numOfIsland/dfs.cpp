class Solution {
public:
   int numIslands(vector<vector<char> >& grid)
 {
 	int m = grid.size();
 	int n = (m == 0 ? 0 : grid[0].size());
 	vector< vector<bool> >  visit(m, vector<bool>(n, 0));
 	int count = 0;
 	for (int i = 0; i < m; ++i)
 	{
 		for (int j = 0; j < n; ++j)
 		{
 			if (grid[i][j] =='1' && !visit[i][j])
 			dfs(grid, visit, m, n, count++, i, j);
 		}
 	}
 	return count;
 }

 void dfs(vector<vector<char> > & grid, vector<vector<bool> > & visit, int m, int n, int count, int i, int j)
 {
 	visit[i][j] = 1;
 	if (j - 1 >= 0 && grid[i][j - 1] == '1' && !visit[i][j - 1])
 		dfs(grid, visit, m, n, count, i, j - 1);
 	if (j + 1 < n && grid[i][j + 1] == '1' && !visit[i][j + 1])
 		dfs(grid, visit, m, n, count, i, j + 1);
 	if (i - 1 >= 0 && grid[i - 1][j] == '1' && !visit[i - 1][j])
 		dfs(grid, visit, m, n, count, i - 1, j);
 	if (i + 1 < m && grid[i + 1][j] == '1' && !visit[i + 1][j])
 		dfs(grid, visit, m, n, count, i + 1, j);
 	return ;
 }
};
