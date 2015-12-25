//http://blog.csdn.net/u010738052/article/details/50402386
int longestCommonSubsequence(string s, string t) {
    int m = s.length(), n = t.size();
    vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));// size = (M + 1,N + 1);
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            dp[i][j] = (s[i - 1] == t[j - 1])? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
        int len = dp[m][n];

        string lcs(len, " ");
    for (int i = m, j= n, index = len - 1; i > 0 && j > 0;)
    {
        if (s[i - 1] == t[j - 1]){
            lcs[index--] = s[i - 1];
            --i;
            --j;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) i--;
        else j--;
    }
    cout<<lcs<<endl;
    return len;
}
