class Solution {
public:
    int jump(vector<int>& nums) {
        int i = 0, n = nums.size(), step = 0, end = 0, maxend = 0;
        while (end < n - 1) {
          step++;
          for (; i <= end; ++i)
          {
            if (i + nums[i] >= n - 1)return step;
            maxend = max(maxend, i + nums[i]);
          }
          end = maxend;
        }
        return step;
        }
};
