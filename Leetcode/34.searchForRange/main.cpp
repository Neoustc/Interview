class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = left(nums, target);
        if (l == -1) return {-1, -1};
        return {l, right(nums, target)};
    }
private:
    int left(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, r = n - 1;
        while (l < r) {
            int m = l + ((r - l) >> 1);
            if (nums[m] < target) l = m + 1;
            else r = m;
        }
        return nums[l] == target ? l : -1;
    }
    int right(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, r = n - 1;
        while (l < r) {
            int m = l + ((r - l + 1) >> 1);     //bias to the right one.
            if (nums[m] > target) r = m - 1;
            else l = m;
        }
        return r;
    }
};
