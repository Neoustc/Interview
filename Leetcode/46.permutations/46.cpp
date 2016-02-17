 basic idea is :
 A[1] + permutation of (A[1...N] - A[1])
 A[2] + permutation of (A[1...N] - A[2])
 A[3] + permutation of (A[1...N] - A[3])
 //[1,2,3] :
// 123;
// 132
// 213
// 231
// 321
// 312
 vector<vector<int> > permute(vector<int>& nums) 
{
    vector<int> v;
    vector<vector<int> > res;
    helper(nums, res, 0);
    return res;
}

void helper (vector<int>& nums, vector<vector<int> >& res, int begin)
{
    if (begin >= nums.size())
    {
        res.push_back(nums);
        return;
    }
    for (int i = begin; i < nums.size(); ++i)
    {
        swap (nums[i], nums[begin]);
        helper(nums, res, begin + 1);
        swap (nums[i], nums[begin]);
    }
}
//
