int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        while (nums.size() <= 2)
            return accumulate(nums.begin(), nums.end(), 0);
        int ans = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int temp = nums[i] + nums[left] + nums[right];
                if (abs(temp - target) < abs(ans - target))
                    ans = temp;
                if (temp == target) return ans;
                if (temp > target) right--;
                else left++;
            }
        }
        return ans;
    }
