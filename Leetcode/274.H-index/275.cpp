class Solution {
public:
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
	return  n - r - 1; // n - l;
}
};
