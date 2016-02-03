//http://blog.csdn.net/u010738052/article/details/50405882
//dp[i] = dp[i - 1] + 1       if nums[i] > nums[i - 1];
dp[i] = max(dp[j]) + 1		if nums[i] <= nums[i - 1] && nums[i] > nums[j];

 int lengthOfLIS(vector<int>& nums) 
 {
 	int n = nums.size();
 	if (!n) return 0;
 	vector<int> dp(n, 1);
 	int res = 1;
 	for (int i = 1; i < n; ++i)
 	{
 	  for (int j = i - 1; j >= 0; j--)
 			{
 				if (nums[i] > nums[j])
 					dp[i] = max(dp[i], dp[j] + 1);
 			    res = max(res, dp[i]);
 			}
 	}
 	 return res;
 }
____________________________________________
int lengthOfLIS(vector<int>& nums) 
{
	int n = nums.size();
	if (!n) return 0;
	vector<int> ends{nums[0]};
	int res = 1;
	for (int num : nums)
	{
		if (num > ends.back())
			ends.push_back(num);
		else if (num < ends[0]) ends[0] = num; 
		else{
			int l = 1, r = ends.size() - 1;
			while (l < r - 1)
			{
				int m = l + ((r - l) >> 1);
				if (ends[m] < num) l = m + 1;
				else r = m;
			}
			ends[l] = num; 
		}
	}
	return ends.size();
}
}

************************************************
int lengthOfLIS(vector<int>& nums) {
    vector<int> res;
    for(int i=0; i<nums.size(); i++) {
        auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
        if(it==res.end()) res.push_back(nums[i]);
        else *it = nums[i];
    }
    return res.size();
}
