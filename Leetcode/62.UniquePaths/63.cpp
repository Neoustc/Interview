 int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) 
{
	int m = obstacleGrid.size(), n = m ? obstacleGrid[0].size() : 0;
		vector<int> cur(m, 0);
    	for (int i = 0; i < m; i++) {
            if (!obstacleGrid[i][0])
                cur[i] = 1;
            else break;
        }
     for (int j = 1; j < n; ++j)
     {
     	if (obstacleGrid[0][j - 1] || obstacleGrid[0][j]) cur[0] = 0;
     for (int i = 1; i < m; ++i)
     	{
     		if (obstacleGrid[i][j]) cur[i] = 0;
     		else {
     			cur[i] += cur[i - 1];
     		}
     	}
     }
     return cur[m - 1];
}
