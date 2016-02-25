 int coinChange (vector<int> & coins, int amount)
{
	int count = 0;
	vector<int> cnt(amount);
	return helper(coins, amount, cnt);
}

int helper (vector<int>& coins, int amount, vector<int>& cnt)
{
	if (amount < 0) return - 1;
	if (amount == 0) return 0;
	if (cnt[amount - 1] != 0) return cnt[amount - 1];
	int min = INT_MAX;
	for (int coin : coins)
	{
		int res = helper (coins, amount - coin, cnt);
		if (res >= 0 && res < min)
			min = res + 1;
	}
	cnt [amount - 1] = (min == INT_MAX) ? -1: min;
	return cnt[amount - 1];
}
