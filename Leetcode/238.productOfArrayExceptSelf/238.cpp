suppose we got a vector : nums[4]
the result array is simply the product of corresponding terms of these two arrays:
[                 1,        nums[0], nums[0] * nums[1], nums[0] * nums[1] * nums[2]]

[nums[1] * nums[2] * nums[3], nums[2] * nums[3],        nums[3],                  1]

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prod(n, 1);
        for (int i = 1; i < n; i++)
            prod[i] = prod[i - 1] * nums[i - 1];
        for (int i = n - 1, r = 1; i >= 0; r *= nums[i--])
            prod[i] *= r;
        return prod;
    }
};
