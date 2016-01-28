class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
  int maxDiffSubArrays(vector<int> nums) 
{
	int n = nums.size();
	vector<int> maxLeft(n);
	vector<int> minLeft(n);
	vector<int> maxRight(n);
	vector<int> minRight(n);
	int maxSum = INT_MIN, minSum = INT_MIN;
	int suma = 0, sumi = 0, minSumi = 0, minSuma = 0; 
	for (int i = 0; i < n; ++i)
	{
		suma += nums[i];
		maxSum = max (maxSum, suma - minSuma);
		minSuma = min (minSuma, suma);
		maxLeft[i] = maxSum;

		sumi += -nums[i];
		minSum = max (minSum, sumi - minSumi);
		minSumi = min (minSumi, sumi);
		minLeft[i] = - minSum;
	}
	maxSum = INT_MIN, minSum = INT_MIN;
	suma = 0, sumi = 0, minSumi = 0, minSuma = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		suma += nums[i];
		maxSum = max (maxSum, suma - minSuma);
		minSuma = min (minSuma, suma);
		maxRight[i] = maxSum;

		sumi += -nums[i];
		minSum = max (minSum, sumi - minSumi);
		minSumi = min (minSumi, sumi);
		minRight[i] = - minSum;
	}
	int Diff = INT_MIN;
	for (int i = 0; i < n - 1; ++i)// I < N - 1;
	{
		Diff = max(Diff, abs(maxLeft[i] - minRight[i + 1]));
		Diff = max(Diff, abs(minLeft[i] - maxRight[i + 1]));
	}
	return Diff;
}
};
