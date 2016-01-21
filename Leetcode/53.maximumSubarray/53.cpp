//maintain a running maximum maxsum and a current summation sum.
//when we visit each num in nums, add num to sum,then update the maxsum if necessary.
//or reset the sum to 0 if  it becomes negative. 
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
