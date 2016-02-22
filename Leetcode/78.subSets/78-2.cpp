  vector<vector<int> > subsets(vector<int>& nums) 
 {
 	sort(nums.begin(), nums.end());
 	vector<vector<int> > res;
 	vector<int> v;
 	res.push_back(v);
 	for (int i = 0; i < nums.size(); ++i)
 		{
 			int n = res.size();
 			for (int j = 0; j < n; ++j)
 			{
 				v = res[j];
 				v.push_back(nums[i]);
 				res.push_back(v);
 			}
 		}
 		return res;
 }
