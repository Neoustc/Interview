class Solution {
public:
  vector<vector<string> > groupAnagrams(vector<string> &strs) 
{
	vector<string> sortStr = strs;
	vector<vector<string> > res;
	unordered_map <string, vector<int> > mp;
	for (int i = 0; i < sortStr.size(); ++i)
	{
	sort(sortStr[i].begin(), sortStr[i].end());
		mp[sortStr[i]].push_back(i);
	}
	for (auto p : mp )
	{
		vector<string> v;
		for (auto i : p.second)
			v.push_back(strs[i]);
		sort(v.begin(), v.end());
		res.push_back(v);
	}
	return res;
}
};
