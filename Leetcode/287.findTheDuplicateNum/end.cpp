//value 1 - n
// index 0 - n - 1
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), slow = n - 1, fast = n - 1;
        do {
            slow = nums[slow] - 1;
            fast = nums[nums[fast] - 1] - 1;
        } while (slow != fast);
        fast = n - 1; 
        do {
            slow = nums[slow] - 1;
            fast = nums[fast] - 1;
        } while (slow != fast);
        return slow + 1;
    }
};
