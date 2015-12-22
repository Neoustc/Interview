//http://blog.csdn.net/u010738052/article/details/50378488
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> windows;
        for (int i = 0; i < nums.size(); i++) {
            auto pos = windows.lower_bound(nums[i] - t);
            if (pos != windows.end() && *pos <= (long long)nums[i] + t)
                return true;
            windows.insert(nums[i]);
            if (i >= k) windows.erase(nums[i - k]);
        }
        return false;
    }
