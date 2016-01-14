 int maxProfit(vector<int>& prices) 
     {
    int n = prices.size();
 	if (n <= 1) return 0;
 	int minPrice = prices[0];
 	int maxProfit = 0;
 	for (auto p : prices)
 	{
 		if (p < minPrice) minPrice = p;
 		maxProfit = max(maxProfit, p - minPrice);
 	}
 	return  maxProfit;
    }
