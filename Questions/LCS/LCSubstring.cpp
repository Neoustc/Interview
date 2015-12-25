//http://blog.csdn.net/u010738052/article/details/50402386
string longestCommonSubstring(string s, string t) 
{
    int m = s.size(), n = t.size();
    vector<vector<int> > dp (m, vector<int>(n, 0));
    int start = 0, len = 0;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
        {
            if (i == 0 || j == 0) dp[i][j] = (s[i] == t[j]);
            else if (s[i] == s[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = 0;
            //else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            if (dp[i][j] > len){
                len = dp[i][j];
                start = i - len + 1;
            } 
        }
        return s.substr(start, len);
}
