class Solution {
public:
   int totalNQueens(int n) {
	int count = 0;
	vector<int> v(n, 0);
 	helper(n, 0, count, v);
 	return count;
}
void helper(int n, int start, int& count, vector<int>& v)
{
	if (start == n)
	{
		count++;
		return;
	}
	for (int i = 0; i < n; ++i)
	{
		v[start] =  i;
		if (isValid(v, start))
			helper(n, start + 1, count, v);
	}
}
	bool isValid(vector<int>& v, int start)
	{
		for (int i = 0; i < start; ++i)
			if (abs(i - start) == abs(v[i] - v[start]) || v[i] == v[start]) return 0;
		return 1;
	}

};
