// dp[i] : means the number of coins need to sum up to the amount i;
// so dp[i] = min (dp[i], dp[i - c] + 1)// for each coin
// if the dp[i - c] is unreachable or the value is INT_MAX, it means we can't 
// 	update the dp[i] through dp[i - c], so just cotinue the loop;
  int coinChange(vector<int>& coins, int amount) 
 {
	 	sort(coins.begin(), coins.end());
	 	vector<int> dp(amount + 1, INT_MAX);
	 	dp[0] = 0;
 	    for (int c : coins)
	 	 	for (int j = c; j <= amount; j++)
	 	 	{
	 	 	    if(dp[j - c] == INT_MAX)
	 	 	        continue;
	 	 		dp[j] = min(dp[j], dp[j - c] + 1);
	 	 	}

	 	 	return (dp[amount] == INT_MAX ? -1 : dp[amount]);
 }
};
