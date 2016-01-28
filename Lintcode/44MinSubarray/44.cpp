class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
     // 
    int minSubArray(vector<int> nums) {
        // write your code here
        int n = nums.size();
        for (int i = 0; i < n; ++i)
            nums[i] = - nums[i];
        int sum = nums[0], maxSum = nums[0];
        for (int i = 1; i < n; ++i)
        {
            if (sum < 0 )
                sum = 0;
            sum += nums[i];
            maxSum = max(maxSum, sum);
        }
        return - maxSum;
    }
};
