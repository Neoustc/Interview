// go through the nums, if the num n is the start of a streak(n - 1 not in the set), 
// then test m = n + 1, n + 2....stop when the m is not in set. length is m - n;
// since  we check each streak only once. so it's O(n) time.

 int longestConsecutive(vector<int>& nums) 
 {
 	unordered_set<int> st(nums.begin(), nums.end());
 	int res = 0;
 	for (int n : nums)
 	{
 		if (st.count(n - 1) == 0)
 		{
 			int m = n + 1;
 			while (st.count(m) > 0)
 				m++;
 			res = max (res, m - n);
 		}
 	}
 	return res;
 }
