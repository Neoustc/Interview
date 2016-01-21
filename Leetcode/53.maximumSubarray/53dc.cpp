// The DC algo breaks nums into two halves and find the maximum subarray sum.
// The max subarray sum could be the subarray in left halves or the right halves subarray.
// or the subarray may span the two halves, across the middle.
// For last case, we use a linear algorithm. 
class Solution {
public:
   int maxSubArray(vector<int>& nums) 
 {
 	int n = nums.size() - 1;
   return  maxSub(nums, 0, n);
 }

 int maxSub(vector<int> & nums, int l , int r)
 {
 	if (l == r) return nums[l];
 	int m = l + (r - l) / 2;
 	int left = maxSub(nums, l, m);
 	int right = maxSub(nums, m + 1, r);
 	int sum = 0, leftmax = INT_MIN, rightmax = INT_MIN, i;
 	for (int i = m; i >= l; i--)
 	{
 		sum += nums[i];
 		leftmax = max (leftmax, sum);
 	}
 	for (sum = 0, i = m + 1; i <= r; ++i)
 	{
 		sum += nums[i];
 		rightmax = max (rightmax, sum);
 	}
 	return max(max(left, right), leftmax + rightmax);
 }
};
