class Solution {
public:
   vector<int> searchRange(vector<int>& nums, int target) 
{
	int n = nums.size();
	vector<int> res;
	int low = 0, high = n;
	int mid = 0;
	while (low < high)
	{
		mid = low + ((high - low) >> 1);
		if (target <= nums[mid]) high = mid;
		else low = mid + 1;
	}
	if (nums[low] != target) return {-1, -1};
	res.push_back(low);
	high = n;
	while (low < high - 1)
	{
		mid = low + ((high - low) >> 1);
		if (target >= nums[mid]) low = mid;
		else high = mid;
	}
	res.push_back(low);
	return res;
}
};
