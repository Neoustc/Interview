// DP table represents if s3 is interleaving at (i+j)th position 
// when s1 is at ith position, and s2 is at jth position. 
// 0th position means empty string.
//http://blog.csdn.net/u010738052/article/details/50534552
 bool isInterleave(string s1, string s2, string s3) 
 {
 	int m = s1.size();
 	int n = s2.size();
 	int k = s3.size();
 	if (m + n != k) return false;
 	bool dp[m + 1][n + 1] = {false}; 
 	for (int i = 0; i <= m; ++i)
 		for (int j = 0; j <= n; ++j)
 		{
 			if (i == 0 && j == 0)
 			dp[i][j] = true;
 			else if (i == 0)
 				dp[i][j] = dp[i][j - 1] && s3[i + j - 1] == s2[j - 1];
 			else if (j == 0)
 				dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
 			else dp[i][j] = (dp[i][j - 1] && s3[i + j - 1] == s2[j - 1]) || (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
 		}
 	return dp[m][n];
 }
