class Solution {
public:
    vector< vector<int> >threeSum(vector<int>& nums) {
    	vector<int> v;
    	vector<vector<int> > res;
    	int n = nums.size();
    	if (n < 3) return res; 
    	sort(nums.begin(), nums.end());
    	for (int i = 0; i < n - 2; ++i)
    	{
    		int l = i + 1, r = n - 1;
    		int target = -nums[i];
    		if (i > 0 && nums[i] == nums[i - 1]) continue;//skip the dup
    		while (l < r)
    		{
       			if (nums[l] + nums[r] > target)
    				r--;
    			else if (nums[l] + nums[r] < target)
    				l++;
    			else {
    				v.push_back(nums[i]);
    				v.push_back(nums[l++]);
    				v.push_back(nums[r--]);
    				res.push_back(v);
    				v.clear();
    				while(l < r && nums[l] == nums[l - 1]) l++;// skip the dup
    				while(l < r && nums[r] == nums[r + 1]) r--;//
    			}
    		}
    	}
    	return res; 

    }
};
_____________________________________________________________________________
//more concise:
                  else{
                    vector<int> ans(3);
                    ans[0] = nums[i];
                    ans[1] = nums[l];
                    ans[2] = nums[r];
                    res.push_back(ans);
                    while (l < r && nums[l] == ans[0]) l++;
                    while (r > l && nums[r] == ans[2]) r--;
                    }
