buy[i] means : before day i what is the maxProfit for any sequence end with buy.
sell[i] means : before day i what is the maxProfit for any sequence end with sell.
rest[i] means : before day i what is the maxProfit for any sequence end with rest.
buy[i] = max (rest[i - 1] - price, buy[i - 1]);
sell[i] = max (buy[i - 1] + price, sell[i - 1]);
rest[i] = max (sell[i - 1], buy[i - 1], rest[i - 1])
	buy[i] <= rest[i]
	rest[i] <= sell[i - 1]

buy[i] = max(sell[i - 2] - price, buy[i - 1])
sell[i] = max(buy[i - 1] + price, sell[i - 1])

b2, b1, b0 represents buy[i - 2], buy[i - 1], buy[i];
s2, s1, s0 represents sell[i - 2], sell[i - 1], sell[i];

int maxProfit(vector<int>& prices) 
{
	int n = prices.size();
	if (n <= 1) return 0;
	int b0 = - prices[0], b1 = b0;
	int s0 = 0, s1 = 0, s2 = 0;
	for (int i = 1; i < n; ++i)
	{
		b0 = max(b1, s2 - prices[i]);
		s0 = max(s1, b1 + prices[i]);
		b1 = b0; s2 = s1; s1 = s0;
	}
	return s0;
}
