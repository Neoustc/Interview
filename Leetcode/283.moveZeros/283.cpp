class Solution {
public:
  void moveZeroes(vector<int>& nums) 
{
	int last = 0, cur = 0;
	int n = nums.size() - 1;
	while (cur <= n)
	{
		if (nums[cur] != 0)
			swap(nums[cur], nums[last++]);
		cur++;
	}
}
};
