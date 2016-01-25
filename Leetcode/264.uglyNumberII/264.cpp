class Solution {
public:
    int nthUglyNumber(int n) 
{
	if (n == 1) return 1;
	int i = 0, j = 0, k = 0;
	int s = 0;
	vector<int> ugly(n);
	ugly[0] = 1;
	for (int s = 1; s < n; s++)
	{
		int num = min(ugly[i] * 2, min(ugly[j] * 3, ugly[k] * 5)); 
		//cout<<i << j << k <<endl;
		if (num % 2 == 0) i++;
		if (num % 3 == 0) j++;
		if (num % 5 == 0) k++;
		ugly[s] = num;
	}
	return ugly[n - 1];
}
};
