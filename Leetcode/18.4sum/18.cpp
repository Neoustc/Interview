class Solution {
public:
    vector< vector<int> > fourSum(vector<int>& nums, int target) {
    	vector<int> v;
    	vector< vector<int> > res;
    	int n = nums.size();
    	if (n < 1) return res;
    	sort(nums.begin(), nums.end());
    	for (int i = 0; i < n - 3; i++)
    	{
    		int tar = target - nums[i];
    		if (i > 0 && nums[i] = nums[i - 1]) continue;
    		for (int j = i + 1; j < n - 2; j++)
    			{
    				if (j > i + 1 && nums[j] = nums[j - 1]) continue;
    				int t = tar - nums[j];
    				int l = j + 1, r = n - 1;
    				while (l < r)
    				{
    					if (nums[l] + nums[r] == t)
    					{
    						v.push_back(nums[i]);
    						v.push_back(nums[j]);
    						v.push_back(nums[l]);
    						v.push_back(nums[r]);
    						res.push_back(v);
    						while (l < r && nums[l] == v[2]) l++;
    						while (l < r && nums[r] == v[3]) r--;
    						v.clear();
    					}
    					else if (nums[l] +  nums[r] > t) r--;
    					else l++;
    				}
    			}
    	}
    	return res;
    }
};
