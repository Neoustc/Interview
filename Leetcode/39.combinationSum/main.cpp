//http://blog.csdn.net/u010738052/article/details/50411261
class Solution {
public:
vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
		int n = candidates.size();
		vector<int> v;
		vector<vector<int> > res;
		if (n == 0) return  res;
		sort(candidates.begin(), candidates.end());
		combine(res, v, candidates, target, 0);
		return res;
}

void combine(vector<vector<int> >& res, vector<int>& v, vector<int>& candidates, int target, int start)
{
	if (target == 0)
	{
		res.push_back(v);
		return ;
	}

	for (int i = start; i < candidates.size() && candidates[i] <= target; ++i)
	{
		v.push_back(candidates[i]);
		combine(res, v, candidates, target - candidates[i], i);
		v.pop_back();
	}
}

//________________________________________________________
//dp 
class Solution {
public:
vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(),candidates.end());
		vector<vector<int> > res;
		vector<vector<vector<int> > > dp(target + 1, vector<vector<int>>());
		dp[0].push_back(vector<int>());
		for (auto& num : candidates)
		{
			for (int j = 0; j <= target - num; ++j)
			{
				auto s = dp[j];
				if (s.size() > 0)
				{
					for (auto& t : s)
						t.push_back(num);
						dp[j + num].insert(dp[j + num].end(), s.begin(), s.end());

				}
			}
		}
		return dp[target];
}
};
