 //https://leetcode.com/discuss/43175/c-solution-with-explanation-o-n-time-and-o-1-space
 vector<int> majorityElement(vector<int>& nums) {
 	int n = nums.size();
 	int candidate1 = 0, count1 = 0;
 	int candidate2 = 0, count2 = 0;
 	vector<int> res;
 	for (auto i : nums)
 	{
 		if (i == candidate1)
 			count1++;
 		else if (i == candidate2)
 			count2++;
 		else if (count1 == 0)
 		{
 			candidate1 = i;
 			count1 = 1;
 		}
 		else if (count2 == 0)
 		{
 			candidate2 = i;
 			count2 = 1;
 		}
 		else {
 			--count1;
 			--count2; 
 		}
 	}
 	count1 = count2 = 0;
 	for (int n : nums)
 	{
 		if (n == candidate1) count1 ++;
 		else if (n == candidate2) count2++;
 	}
 	if (count1 > nums.size() / 3) res.push_back(candidate1);
 	if (count2 > nums.size() / 3) res.push_back(candidate2);
 	return res;
 }
