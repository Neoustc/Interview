vector<vector<int> > subsets(vector<int>& nums) 
 {
 	vector<vector<int> > res;
 	vector<int> v;
 	int n = nums.size();
 	sort(nums.begin(), nums.end());
 	genSet(nums, res, v, 0);
 	return res;
 }

void genSet(vector<int>& nums, vector<vector<int> > & res, vector<int> & v, int start)
{
	res.push_back(v);
	for (int i = start; i < nums.size(); ++i)
	{
		v.push_back(nums[i]);
		genSet(nums, res, v, i + 1);
		v.pop_back();
	}
	return;
}
