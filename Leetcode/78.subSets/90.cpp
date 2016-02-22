class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) 
 {
 	vector<vector<int> > res;
 	vector<int> v;
 	sort(nums.begin(), nums.end());
 	genSub(nums, res, v, 0);
 	return res;
 }

 void genSub(vector<int>& nums, vector<vector<int>> & res, vector<int>& v, int start)
 {
 	res.push_back(v);
 	for (int i = start; i < nums.size(); ++i)
 	{
 		if (i == start || nums[i] != nums[i - 1])
 		{
 		v.push_back(nums[i]);
 		genSub(nums, res, v, i + 1);
 		v.pop_back();
 		}
 	}	
 	return;
 }
};
