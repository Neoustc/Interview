 int maxProfit(vector<int>& prices)
  	{
 	int n = prices.size();
	if (n <= 1) return 0;
	int i = 0, j = 0;
	int minPrices = prices[0];
	int maxProfit = 0;
	while (i < n)
	{
		if (prices[i] <= prices[i + 1])
		{ 
			while (i + 1 < n && prices[i] <= prices[i + 1]){++i;}
				maxProfit += prices[i] - minPrices;
				if (i + 1 >= n) return maxProfit; 
		}
		else
		{
			while (i + 1 < n && prices[i] > prices[i + 1]){++i;}
				minPrices = prices[i];
			if (i + 1 >= n) return maxProfit;
		}
	} 	
 }
