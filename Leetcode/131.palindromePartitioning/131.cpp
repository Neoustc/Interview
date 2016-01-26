class Solution {
public:
    vector<vector<string> > partition(string s) {
    int n = s.size();
 	vector<vector<string> > res;
 	vector<string> v;
 	helper(res, v, s, 0);
 	return res;
    }
    void helper(vector<vector<string> >& res, vector<string>& v, string s, int start)
 {
 	if (start == s.size())
 	{
 		res.push_back(v);
 		return;
 	}
 	for (int i = 1; i <= s.size() - start; ++i)
 	{
 		string t = s.substr(start, i);
 		if (isvalid(t))
 			{
 			v.push_back(t);
 			helper(res, v, s, start + i);
 			v.pop_back();
 			}
 	}
 }
 bool isvalid (string s)
 {
 	int n = s.size(); 	
 	for (int i = 0, r = n - 1; i < r; ++i, --r)
 		if (s[i] != s[r]) return false;
 	return true;
 }
};
