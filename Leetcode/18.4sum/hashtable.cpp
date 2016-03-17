//storing all the possible sum of a pair of elements in nums first.
//hash table with the key as the sum of the pair, the value as a vector store the indice of the num that having the same sum
// WORST case is O(n^4),since the the vector in the map is not constant, the total amount of all the pair sum  is n^2. 
vector< vector<int> > fourSum(vector<int>& nums, int target) 
{
	sort(nums.begin(), nums.end());
	unordered_map<int, vector<pair<int, int> > > mp;
	int n = nums.size();
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			mp[nums[i] + nums[j]].push_back(make_pair(i,j));
	vector<vector<int> > res;
	for (int i = 0; i < n - 3; ++i)
	{
		if (i > 0 && nums[i] == nums[i - 1]) continue;
		for (int j = i + 1; j < n; ++j)
		{
			if (j > i + 1 && nums[j] == nums[j - 1]) continue;
			int remain = target - nums[i] - nums[j];
				if (mp.count(remain))
				{
					for (auto itr : mp[remain])
					{
						int k = itr.first, l = itr.second;
						if (k > j) //avoid dups;
						{
							vector<int> ans(4);
							ans[0] = nums[i];
							ans[1] = nums[j];
							ans[2] = nums[k];
							ans[3] = nums[l];
						if (res.empty() || ans != res.back())// k,l could have dups, skip them 
							res.push_back(ans);
						}

					}

				}
		}

	}
	return res;
}
