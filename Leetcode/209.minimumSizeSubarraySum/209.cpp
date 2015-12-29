int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int l = 0, sum = 0;
        int length = n + 1;
    for (int r = 0; r < n; ++r)
    {
        if (nums[r] >= s) return 1;
        sum += nums[r];
        while (sum >= s) {
            length = min(length, r - l + 1);
            sum -= nums[l++];
        }
    }
    return length == n + 1? 0 : length;
}
