//http://blog.csdn.net/u010738052/article/details/50807194
// index [0...n - 1]; n  nums
// digit [1...n - 1];
int findDuplicate(vector<int>& nums) 
{
	int n = nums.size();
	if(n <= 1) return -1;
	int slow = nums[0], fast = nums[nums[0]];
	while (slow != fast)
		{
			slow = nums[slow];
			fast = nums[nums[fast]];
		}
	fast = 0;
	while (fast != slow)
	{
		fast = nums[fast];
		slow = nums[slow];
	}
	return slow;
}
*****************************************
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

**********************************************
int findDuplicate(vector<int>& nums) 
	{
		int n = nums.size() - 1, res = 0;
		for (int p = 0; p < 32; ++p)
		{
			int bit = (1 << p), a = 0, b = 0;
			for (int i = 0; i <= n; ++i)
			{
				if (i > 0 && (i & bit) > 0) ++a;
				if ((nums[i] & bit) > 0) ++b;
			}
			if (b > a) res += bit;
		}
		return res;
	}


