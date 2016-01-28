bool knows(int a, int b)
int findCelebrity(int n) 
{
	vector<int> candidates(n);
	iota(candidates.begin(),candidates.end(), 0);
	while (candidates.size() > 1)
	{
		int a = candidates.back(); 
		candidates.pop_back();
		int b = candidates.back();
		candidates.pop_back();
		if (knows(a,b)) candidates.push_back(b);
		else candidates.push_back(a);
	}
	return verify(candidates[0], n);
}
int verify(int c, int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (i != c && (knows(c, i) || !knows(i ,c))
			return -1;
	}
	return c;
}
