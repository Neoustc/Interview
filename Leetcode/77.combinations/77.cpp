class Solution {
public:
    vector<vector<int> > combine(int n, int k) 
    {
    	vector<vector<int> > res;
    	vector<int> v;
    	if (k == 0 || k > n) return res;//not necessary
    	helper(res, v, n, k, 1);// 
    	return res;
    }

    void helper(vector<vector<int> >& res, vector<int>& v, int n, int k, int start)
    {
		if (k == 0)//
		{
			res.push_back(v);
			return;
		}    	
		for (int i = start; i <= n; ++i)// i <= n
		{
			v.push_back(i);
			helper(res, v, n, k - 1, i + 1);
			v.pop_back();
		}
    }
};
