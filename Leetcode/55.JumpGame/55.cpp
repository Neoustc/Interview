// greedy
class Solution {
public:
    bool canJump(vector<int>& nums) 
 {
 	int n = nums.size();
 	int reach = 0, i = 0;
 	for (; i < n && i <= reach; ++i)
 	{
 		reach = max(reach, i + nums[i]);
 	}
 	return i == n;
 }
};
