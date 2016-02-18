int maximalSquare(vector<vector<char>>& matrix)
{
	int m = matrix.size();
 	int n = m ? matrix[0].size() : 0;
 	int maxLen = 0;
 	vector<int> pre(m, 0);
 	vector<int> cur(m, 0);
 	for (int i = 0; i < m; ++i)
 	{
 		if (matrix[i][0] == '1')
 		maxLen = pre[i] = 1;
 	}
 	for (int j = 1; j < n; ++j)
 		{
 			cur [0] = matrix[0][j] - '0';
 			maxLen = max(maxLen, cur[0]);
 			for (int i = 1; i < m; ++i)
 			{
 			    if (matrix[i][j] == '1')
 			    {
 				cur[i] = min( min (pre[i], pre[i - 1]), cur[i - 1]) + 1;
 				maxLen = max(maxLen, cur[i]);
 			    }
 			    else cur[i] = 0;
 			}
 			pre = cur;
 		}
 		return maxLen * maxLen;
}
