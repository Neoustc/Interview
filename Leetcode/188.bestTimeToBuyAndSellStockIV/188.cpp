class Solution {
public:
 int maxProfit(int k, vector<int>& prices) {
    	int n = prices.size();
    	if (n <= 1) return 0;
    	if (k >= n / 2) return quicksolve(prices);
    	vector< vector<int> > dp (k + 1, vector<int>(n));//put behind the quicksolve else runtime error
    	for (int kk = 1; kk <= k; kk++)
    	{
    		int tmpMax = dp[kk - 1][0] - prices[0];
    		for (int ii = 1; ii < n; ii++)
    		{
    			dp[kk][ii] = max(dp[kk][ii - 1], prices[ii] + tmpMax);
    			tmpMax = max(tmpMax, dp[kk - 1][ii] - prices[ii]);	
    		}
    	}
    	return dp[k][n - 1];

    }

    int quicksolve(vector<int> & prices)
    {
    	int n = prices.size(), maxProfit = 0;
    	for (int i = 1; i < n; ++i)
    		if (prices[i] > prices[i - 1])
    			maxProfit += prices[i] - prices[i - 1];
    	return maxProfit;

    }
};
