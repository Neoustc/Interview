//unordered_map.find(key) return the value;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
   {
    	int n = nums.size();
    	if (k <= 0) return 0;
    	unordered_map<int, int> mp;
    	for (int i = 0; i < n; ++i)
    	{
    	auto got = mp.find(nums[i]);
    	if (got != mp.end())
    	{
    		if (i - mp[nums[i]] <= k) return true;
    	}
    	 mp[nums[i]] = i;
    	}
    	return false;
    }
};

