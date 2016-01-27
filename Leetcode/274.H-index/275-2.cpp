we want to find the minimum index 
that 
citations[m] >= n - m;

  int hIndex(vector<int>& citations) 
{
	int l = 0, n = citations.size() , r = n;
	int m = 0;
	while (l < r)
	{
		m = l + ((r - l) >> 1);
		if (citations[m] > n - m) 
			r = m;
		else if (citations[m] < n - m) 
			l = m + 1;
		else return citations[m];
	}
	return n - l;//n -r both ok;
}



int hIndex(vector<int>& citations) 
{
	int l = 0, n = citations.size() , r = n - 1;
	int m = 0;
	while (l <= r)
	{
		m = l + ((r - l) >> 1);
		if (citations[m] > n - m) 
			r = m - 1;
		else if (citations[m] < n - m) 
			l = m + 1;
		else return citations[m];
	}
	return n - l;
}
