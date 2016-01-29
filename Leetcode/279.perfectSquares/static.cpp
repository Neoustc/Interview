class Solution {
public:

   int numSquares(int n) 
 {
    static vector<int> dp(1, 0);
 //	vector<int > dp(n + 1, INT_MAX);
 //	dp[0] = 0; dp[1] = 1;
    if (dp.size() <= n) 
    {
 	 for (int i = dp.size(); i <= n; ++i)
 	    {
 	       int t = INT_MAX;
 		for (int j = 1; j * j <= i; j++)
 			{
 				t = min(t, 1 + dp[i - j * j]);
 			}
 			dp.push_back(t);
 	    }
    }
 	return dp[n];
 }
};
