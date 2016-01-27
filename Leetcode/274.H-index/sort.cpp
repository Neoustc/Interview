class Solution {
public:
   int hIndex(vector<int>& citations) {
	sort(citations.rbegin(), citations.rend());//descending
 	int h = 0;
 	for (int i = 0; i < citations.size(); ++i)
 	{
 		if ((i + 1) <= citations[i]) {
 			h = max(h, i + 1);
 		}
 	}
 	return h;
	}
};

***********

 int hIndex(vector<int>& citations) {
	sort(citations.begin(), citations.end());//descending
 	int h = 0;
 	int n = citations.size();
 	for (int i = n - 1; i >= 0; --i)
 	{
 		if ((n - i) <= citations[i]) {
 			h = max(h, n - i);
 		}
 	}
 	return h;
	}
