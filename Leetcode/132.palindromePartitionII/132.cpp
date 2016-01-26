// dp[i] : the min cut for string[0...i - 1];
// ispal[j][i] : whether the string s[j....i] is a palindrome;
  int minCut(string s) 
{
	int n = s.size();
	vector<vector<bool> > isPal (n, vector<bool> (n, false));
	vector<int> dp(n);
	for (int i = 0; i < n; ++i)
	{
		dp[i] = i;
		for (int j = 0; j <= i ; ++j)
		{
			if (s[j] == s[i] && (i - j < 2 || isPal[j + 1][i - 1]))// check the value of ispal[j][i]
			{
				isPal[j][i] = true;
				if (j == 0) //  is palindrome 
					dp[i] = 0;
				else if (dp[j - 1] + 1 < dp[i]) // update min cut
					dp[i] = dp[j - 1] + 1;
			}
		}
	}
	return dp[n - 1];
}
