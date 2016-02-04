class NumMatrix {
public:
    NumMatrix(vector<vector<int> > &matrix) {
 		int m = matrix.size(), n = m ? matrix[0].size() : 0;
 		vector<int> v(n + 1);
 		dp.push_back(v);
 		for (int i = 1; i <= m; ++i)
 		{
 			dp.push_back(v);
 			for(int j = 1; j <= n; ++j)
 			{
 				 dp[i][j] = matrix[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
 			}
 		}
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2 + 1][col2 + 1] + dp[row1][col1] - dp[row2 + 1][col1] - dp[row1][col2 + 1];
    }
 private:
 	vector<vector<int> > dp;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
