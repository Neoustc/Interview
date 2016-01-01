//http://blog.csdn.net/u010738052/article/details/50447394
class Solution { 
public:
     vector< vector <string> > solveNQueens(int n) 
 {  
 	vector<vector<string> > res;
 	vector<int> v(n, 0);
 	helper(n, 0, res, v);
 	return res;
 }
 void helper(int n, int start, vector<vector<string> >& res, vector<int>& v)
 {
 	if (start == n)
 	{
 		res.push_back(toStr(v));
 		return;
 	}
 	for (int index = 0; index < n; ++index)
 	{
 		v[start] = index;
 		if (isValid(v, start))
 		helper(n, start + 1, res, v);
 	}
 }
 bool isValid(vector<int> & v, int n)
 {	
 	for (int i = 0; i < n; i++)
 	{
 		if(abs(n - i) == abs(v[n] - v[i]) || v[i] == v[n])
 			return 0;
 	}
 	return 1;
 }

 vector<string> toStr(vector<int>& v){
 	int n = v.size();
 	vector<string> rel;
 	for (int i = 0; i < n; ++i)
 	{
 		string t(n, '.');
 		t[v[i]] = 'Q';
 		rel.push_back(t);
 	}
 	return rel;
 }
};
