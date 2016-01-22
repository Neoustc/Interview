class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
 	int t = 0;
 	for (auto i : nums) t ^= i;
 	int s1 = 0, s2 = 0; 
 	t &= -t ;// and with complement
 	for (int i : nums)
 	{
 		if (i & t) {
 			s1 ^= i; 
 		} 
 		else s2 ^= i;
 	} 
 	return {s1, s2};
 }
};
