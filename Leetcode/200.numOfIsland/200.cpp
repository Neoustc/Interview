class Solution {
public:
 int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
 int numIslands(vector<vector<char> >& grid)
 {
 	int m = grid.size(), n = m ? grid[0].size() : 0; 
 	int count = 0;
 	vector<vector<bool> > visited(m, vector<bool>(n, false));
 	for (int i = 0; i < m; ++i)
 		for (int j = 0; j < n; j++)
 		{
 			if (grid[i][j] == '1' && !visited[i][j])
 				{
 					visit(grid, m, n, i, j, visited);
 					count++;
 				}
 		}
 		return count;
 }

 void visit(vector<vector<char> > & grid, int& m, int& n, int i, int j, vector<vector<bool> > & visited)
 {
 	visited[i][j] = true;
 	for(int d = 0; d < 4; d++)
 	{
 		int x = i + dir[d][0];
 		int y = j + dir[d][1];
 		if (0 <=x && x < m && 0 <= y && y < n && grid[x][y] == '1' && !visited[x][y] )
 			visit(grid, m, n, x, y, visited);
 	}
 	return;
 }
};
