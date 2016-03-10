 int numDistinct(string s, string t) 
 {	
 	int m = t.size(), n = s.size();
 	int dp[m + 1] = {1};
 	for (int j = 1; j <= n; ++j)
 		{
 		    int pre = 1;
 		for (int i = 1; i <= m; ++i)
	 		{
	 			int tmp = dp[i];
	 			dp[i] = dp[i] + (t[i - 1] == s[j - 1] ? pre : 0);
	 			pre = tmp;
	 		}
 		}
 	return dp[m];
 }
