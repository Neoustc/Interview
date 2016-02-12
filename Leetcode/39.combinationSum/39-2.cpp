vector<vector<int> > combinationSum(vector<int>& candidates, int target) 
{
	vector<int> v;
	int n = candidates.size();
	sort(candidates.begin(),candidates.end());
	vector<vector<vector<int> > >  dp;//(target + 1, vector<vector<int>> ());
	dp.push_back( vector<vector<int> >  ());
	for (int i = 1; i <= target; ++i)
	{
		vector<vector<int> > v;
		for (int j = 0; j < n && candidates[j] <= i; ++j)
		{
			if (i == candidates[j])
			{
				v.push_back ({candidates[j]});
			}
			else 
			{
			    for (auto l : dp[i - candidates[j]])
				{
					if (candidates[j] >= l.back())
					{
						vector<int> t = l;
						t.push_back(candidates[j]);
						v.push_back(t);
					}
				}
			}
		}
		dp.push_back(v);
	}
	return dp[target];
}
