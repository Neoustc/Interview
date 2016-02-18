//dp[i][j] represent the max length of the square that [i][j] is the bottom right of the square;
//dp[i][j] = min (dp[i - 1][j], dp[i - 1][j - 1], dp[i][ j - 1]);
  int maximalSquare(vector<vector<char>>& matrix) 
 {
 	int m = matrix.size();
 	int n = m ? matrix[0].size() : 0;
 	int maxLen = 0;
 	vector<vector<int> > dp(m, vector<int>(n, 0));
 	for (int i = 0; i < n; ++i)
 		if (matrix[0][i] == '1')
 			{
 			    maxLen = dp[0][i] = 1;
 			}
 	for (int j = 0; j < m; ++j)
 		if (matrix[j][0] == '1')
 			{
 			 maxLen = dp[j][0] = 1;
 			}
 	for (int i = 1; i < m; ++i)
 		for (int j = 1; j < n; ++j)
 		{
 			if (matrix[i][j] == '0')
 				dp[i][j] = 0;
 			if (matrix[i][j] == '1')
 			{
 				dp[i][j] = min (min (dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]) + 1;
 				maxLen = max(dp[i][j], maxLen);
 			}
 		}
 		return maxLen * maxLen;
 }
