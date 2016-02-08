class Solution {
public:
   string largestNumber(vector<int>& nums) 
 {
 	int n = nums.size();
 	sort(nums.begin(), nums.end(), [](int& a, int& b){
 		string s1 = to_string(a);
 		string s2 = to_string(b);
 		return s1 + s2 < s2 + s1;
 	});
 	string res;
 	for (int i = n - 1; i >= 0; --i)
 		res += to_string(nums[i]);
 	while (res[0] == '0' && res.size() > 1)
 		res.erase(0, 1);
 	return res;
 }
};
 
