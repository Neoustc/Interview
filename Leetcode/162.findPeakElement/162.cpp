// find the first peak is easy.
class Solution {
public:
    int findPeakElement(vector<int>& nums) 
 {
 	int n = nums.size();
 	for (int i = 0; i < n; ++i)
 	{
 		if (i + 1 < n && nums[i] > nums[i + 1])
 			return i;
 	}
 	return n - 1;
 }
};
