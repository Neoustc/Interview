//http://blog.csdn.net/u010738052/article/details/50540119
int rob(vector<int>& nums) 
 {
    int n = nums.size();
    int a = 0, b = 0, money = 0;
    for (int i = 0; i < n; ++i)
    {
        money = max(a + nums[i], b);
        a = b;
        b = money;
    }
    return money;
 }
