//http://blog.csdn.net/u010738052/article/details/50540119
class Solution {
private :
int rob(vector<int> &nums, int l, int r)
{
        int pre = 0, cur = 0;
        for (int i = l; i <= r; i++)
        {
            int money = max(pre + nums[i], cur);
            pre = cur;
            cur = money;
        }
        return cur;
}
public :  
    int rob(vector<int>& nums) {
      int n = nums.size();
      if (n < 2) return n ? nums[0] : 0;
      return max(rob(nums, 0, n - 2), rob(nums, 1, n - 1));    
    }
};
