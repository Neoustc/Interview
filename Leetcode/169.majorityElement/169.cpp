
class Solution {
public:
    int majorityElement(vector<int>& nums) {
    int n = nums.size();
	int count = 1;
	int major = nums[0];
	for (int i = 1; i < n; ++i)
	{
		if (nums[i] == major)
			++count;
		else {
			--count;
			if (count < 0)
			{
				major = nums[i]; 
				count = 1; // recover the count;
			}
		}
		if (count > n / 2 + 1) break; // speed up;
	}
	return major;
    }
};
