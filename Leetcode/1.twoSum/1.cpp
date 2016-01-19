//http://blog.csdn.net/u010738052/article/details/50541673
//The idea is maintain a hashtable for each element num in nums, using num 
//as key and its index as value. For each num, search for target - num in the hast table.

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target)
    {
        unordered_map <int, int> mp;
 	int n = numbers.size();
 	for (int i = 0; i < n; ++i)
 	{
 		// if (mp[target - numbers[i]] > 0)   //slower
 		if (mp.find(target - numbers[i]) != mp.end())
 			return {mp[target - numbers[i]], i + 1};
 		mp [numbers[i]] = i + 1;
 	}
    }
};
