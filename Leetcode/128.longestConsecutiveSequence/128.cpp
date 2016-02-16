 The main idea is to use map to keep track of the boundary element and the length of the sequence.
 When a new element n is inserted to the map.
 1. if n - 1 and n + 1 exist in the map, we use left and right to denote the length of two sequences;
 store the (left + right + 1) as the associated value to key n;
 2. Update the boundary and length of current sequences, find the new left and right boundary and set the new length 

 int longestConsecutive(vector<int>& nums) 
 {
 	int res = 0;
 	unordered_map<int, int> mp;
 	for (int n : nums)
 	{
 		if (mp[n] == 0)
 		{
 			int left = mp[n - 1] > 0 ? mp[n - 1] : 0;
 			int right = mp[n + 1] > 0 ? mp[n + 1] : 0;
 			int sum = left + right + 1;
 			mp[n] = sum;
 			res = max(res, sum);
 			mp[n - left] = sum;
 			mp[n + right] = sum;
 		}
 	}
 	return res;
 }
