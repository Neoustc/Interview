int maxCoins(vector<int>& nums) { 
        vector<int> balls(nums.size() + 2);
        int n = 1;
        balls[0] = 1;
        for(int x : nums)
        	if( x > 0) balls[n++] = x;
        balls[n++] = 1;
        int **memo;
	    memo = new int*[n];
        for(int i = 0;i < n; i++)            
         {
            memo[i] = new int[n];
             memset(memo[i], 0, n*sizeof(int));
         }
		return burst(memo, balls, 0, n - 1);
    }

 int burst(int** memo, vector<int> & nums, int left, int right)
 {
 	if (left + 1 == right) return 0;
 	if (memo[left][right] > 0) return memo[left][right];
 	int best = 0;
 	for (int i = left + 1; i < right; ++i)
 	{
 		int l = burst(memo, nums, left, i);
 		int r = burst(memo, nums, i, right);
 		best = max (best, l + r + nums[left] * nums[i] * nums[right]);
 	}
 	memo[left][right] = best;
 	return best;
 } 
