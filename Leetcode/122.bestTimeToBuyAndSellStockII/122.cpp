 // You need to find the peak of the price. then use the peak's price minus the valley's price.
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
			while (i + 1 < n && prices[i] <= prices[i + 1]){++i;}// check whether the price goes up 
				maxProfit += prices[i] - minPrices;// meet the peak calculate the profit.
				if (i + 1 >= n) return maxProfit; 
		}
		else
		{
			while (i + 1 < n && prices[i] > prices[i + 1]){++i;}// check whether the price goes down.
				minPrices = prices[i];// remember the current valley‘s price.
			if (i + 1 >= n) return maxProfit;
		}
	} 	
 }
