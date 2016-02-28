class Solution {
public:
    //dp[left][right] means the coins that you can get when burst the balloons from left to right;
//  
 int maxCoins(vector<int>& nums) 
 {
 	vector<int> balls(nums.size() + 2);
 	int n = 1;
 	balls[0] = 1;
 	//burst all the zero coin balloons
 	for (int x : nums)
 		if (x > 0) balls[n ++] = x;
 	balls[n ++ ] = 1;
 	
 	int dp[n][n] = {};
 	
  for( int len = 2; len < n; len++)//range length 
        {
        	for(int left = 0; left < n - len; ++left)//
        	{	
        		int right = left + len;
        		for(int i = left + 1; i < right; ++i)
	        	{
	        		dp[left][right] = max(dp[left][right], balls[left] * balls[i] * balls[right] + dp[left][i] + dp[i][right]);
	        	}

	        }
		}

//  	for (int left = 0; left < n - 2; ++left)
//  		for (int right = left + 2; right < n; ++right)
//  			for (int i = left + 1; i < right; ++i)
//  			{
//  					dp[left][right] = max(dp[left][right], balls[left] * balls[i] * balls[right] + dp[left][i] + dp[i][right]);
//  			}//wrong solution ,dp starts from bottom up, we calculate each adjacent result first;
 			
 return dp[0][n - 1];
}
};
