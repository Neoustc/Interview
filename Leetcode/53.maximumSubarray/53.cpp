int maxSubArray(vector<int>& nums) 
{
	int n = nums.size();
	if (n == 1) return nums[0];
	int sum = nums[0], maxSum = nums[0];
	for (int i = 1; i < n; ++i)
	{
		if (sum < 0)   // -2, 1
			sum = 0;
		sum += nums[i];
		maxSum = max(sum,maxSum);
	}
	return maxSum;
}
