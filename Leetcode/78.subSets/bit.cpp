 vector<vector<int>> subsets(vector<int>& nums) 
 {
 	sort(nums.begin(), nums.end());
 	int num_subset = pow (2, nums.size());
 	vector<vector<int> >  res (num_subset, vector<int>());
 	for (int i = 0; i < nums.size(); ++i)
 		for(int j = 0; j < num_subset; ++j)
 			if ((j >> i) & 1)
 				res[j].push_back(nums[i]);
 	return res;

 }
