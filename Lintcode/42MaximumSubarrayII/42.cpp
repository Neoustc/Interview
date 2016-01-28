class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
   int maxTwoSubArrays(vector<int> nums) {
        // write your code here
        int n = nums.size();
        int sum = 0, Max = INT_MIN;
        vector<int> maxLeft(n);
        vector<int> maxRight(n);
        int minSum = 0;
        for (int i = 0; i < n; ++i)
           {
               sum += nums[i];
            Max = max (Max, sum - minSum);
               minSum = min (minSum, sum);
               maxLeft[i] = Max;
           }
        sum = 0, minSum = 0;
        Max= INT_MIN;
        for (int i = n - 1; i >= 0; --i)
        {
            sum += nums[i]; 
            Max = max (Max, sum - minSum);
            minSum = min (minSum, sum);
            maxRight[i] = Max;
        }
        Max = INT_MIN;
        for (int i = 0; i < n - 1; ++i)
          Max = max (Max, maxRight[i + 1] + maxLeft[i]);
        return Max;
    }
};
