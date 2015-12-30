class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
    string s = "";
 	vector<string> res;
 	int n = nums.size();
 	for(int i = 0; i < nums.size();)
 		{
 			s += to_string(nums[i]);
 			int tmp = nums[i] - i;
 			++i;
 			while (i < n && nums[i] - i == tmp)
 				++i;
 			if (i <= n && s != to_string(nums[i - 1]))
 				s += "->" + to_string(nums[i - 1]);
 			res.push_back(s);
 			s = ""; 
 		}
        return res;
    }
};
