class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return majority(nums, 0, nums.size() - 1);
    }
private:
    int majority(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];
        int mid = left + ((right - left) >> 1);
        int lm = majority(nums, left, mid);
        int rm = majority(nums, mid + 1, right);
        if (lm == rm) return lm;
        return counts(nums, lm) > counts(nums, rm) ? lm : rm;
    }
    int counts(vector<int>& nums, int elem) {
        int cnt = 0;
        for (int i = 0; i < int(nums.size()); i++)
            if (nums[i] == elem) cnt++;
        return cnt;
    }
};
